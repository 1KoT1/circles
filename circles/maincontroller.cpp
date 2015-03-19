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
	mAppDataModel(appDataModel)
{
}

MainController::~MainController() {

}

void MainController::quit() {
	QCoreApplication::quit();
}

void MainController::startGame() {
}
