#include "maincontroller.h"
#include <QGuiApplication>
#include <QWindow>

#if defined(Q_OS_ANDROID)
const QString pathToSettingFile = "qrc:/input.txt";
#else
const QString pathToSettingFile = "./input.txt";
#endif
const QString radiusOfCirclesSettingName = "RadiusOfCircles";
const QString lifeTimeOfCirclesSettingName = "LifeTime";
const QString bornTimeSettingName = "BornTime";
const QString numberOfSpotsSettingName = "CountPoints";
const QString speedOfSportsSettingName = "SpeedOfPoints";

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

    auto lifeTimeOfCircles = settings.value(lifeTimeOfCirclesSettingName, defaultLifeTimeOfCircles / 1000.0).toDouble(&convertIsOk) * 1000;
	if(!convertIsOk) {
		lifeTimeOfCircles = defaultLifeTimeOfCircles;
	}

    auto timeOfCircleBurn = settings.value(bornTimeSettingName, defaultTimeOfCircleBurn / 1000.0).toDouble(&convertIsOk) * 1000;
	if(!convertIsOk) {
		timeOfCircleBurn = defaultTimeOfCircleBurn;
	}

	auto numberOfSpots = settings.value(numberOfSpotsSettingName, defaultNumberOfSpots).toUInt(&convertIsOk);
	if(!convertIsOk) {
		numberOfSpots = defaultNumberOfSpots;
	}

	auto speedOfSports = settings.value(speedOfSportsSettingName, defaultSpeedOfSports).toDouble(&convertIsOk);
	if(!convertIsOk) {
		speedOfSports = defaultSpeedOfSports;
	}

	mGameController.reset(new GameController(mAppDataModel->gameDataModel(),
																					 radiusOfCircles,
																					 lifeTimeOfCircles,
																					 timeOfCircleBurn,
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

