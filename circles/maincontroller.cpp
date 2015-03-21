#include "maincontroller.h"
#include <QGuiApplication>
#include <QWindow>

#if defined(Q_OS_ANDROID)
const QString pathToSettingFile = "qrc:/Settings.ini";
#else
const QString pathToSettingFile = "./Settings.ini";
#endif
const QString radiusOfCirclesSettingName = "GameParameters/RadiusOfCircles";
const QString lifeTimeOfCirclesSettingName = "GameParameters/LifeTimeOfCircles";
const QString numberOfSpotsSettingName = "GameParameters/NumberOfSpots";
const QString speedOfSportsSettingName = "GameParameters/SpeedOfSports";

MainController::MainController(AppDataModelPtr appDataModel, QObject *parent) :
	QObject(parent),
	mAppDataModel(appDataModel),
	mGameController(nullptr)
{

}

MainController::~MainController() {

}

void MainController::quit() {
	QCoreApplication::quit();
}

void MainController::startGame() {
	QSettings settings(pathToSettingFile, QSettings::IniFormat, this);
	bool convertIsOk = false;

	auto radiusOfCircles = settings.value(radiusOfCirclesSettingName, defaultRadiusOfCircles).toDouble(&convertIsOk);
	if(!convertIsOk) {
		radiusOfCircles = defaultRadiusOfCircles;
	}

	auto lifeTimeOfCircles = settings.value(lifeTimeOfCirclesSettingName, defaultLifeTimeOfCircles).toInt(&convertIsOk);
	if(!convertIsOk) {
		lifeTimeOfCircles = defaultLifeTimeOfCircles;
	}

	auto numberOfSpots = settings.value(numberOfSpotsSettingName, defaultNumberOfSpots).toUInt(&convertIsOk);
	if(!convertIsOk) {
		numberOfSpots = defaultNumberOfSpots;
	}

	auto speedOfSports = settings.value(speedOfSportsSettingName, defaultSpeedOfSports).toDouble(&convertIsOk);
	if(!convertIsOk) {
		speedOfSports = defaultSpeedOfSports;
	}
	qDebug()<<settings.status();

	mGameController.reset(new GameController(mAppDataModel->gameDataModel(),
																					 radiusOfCircles,
																					 lifeTimeOfCircles,
																					 defaultTimeOfCircleBurn,
																					 numberOfSpots,
																					 speedOfSports,
																					 this
																					 ));
	connect(mGameController.get(), SIGNAL(gameStoped()), SLOT(gameStopHandler()));
	connect(&mTimer, SIGNAL(timeout()), mGameController.get(), SLOT(updateScene()));
	emit gameControllerChanged();
	mAppDataModel->setDisplay(Displays::Game);
	mGameController->initGame();
	mTimer.start(udateSceneInterval);
}

GameController *MainController::gameController() const {
	return mGameController.get();
}

void MainController::gameStopHandler() {
	mTimer.stop();
	mGameController.release();
	mAppDataModel->setDisplay(Displays::MainMenu);
}

