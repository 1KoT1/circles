#include "maincontroller.h"
#include <QGuiApplication>
#include <QWindow>

const qreal defaultRadiusOfCircles = 50;
const long defaultLifeTimeOfCircles = 5 * 1000;
const uint defaultNumberOfSpots = 10;
const double defaultSpeedOfSports = 30;
const int udateSceneInterval = 1000 / 25;

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
	mGameController.reset(new GameController(mAppDataModel->gameDataModel(),
																					 defaultRadiusOfCircles,
																					 defaultLifeTimeOfCircles,
																					 defaultNumberOfSpots,
																					 defaultSpeedOfSports,
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

