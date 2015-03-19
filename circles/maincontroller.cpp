#include "maincontroller.h"
#include <QGuiApplication>
#include <QWindow>

const qreal DefaultRadiusOfCircles = 50;
const long DefaultLifeTimeOfCircles = 5 * 1000;
const uint DefaultNumberOfSpots = 10;
const double DefaultSpeedOfSports = 30;
/// Интервал обновления в милисекундах
const int UdateSceneInterval = 1000 / 25;

MainController::MainController(QObject *parent) :
	QObject(parent)
{
}

MainController::~MainController() {

}

void MainController::quit() {
	QCoreApplication::quit();
}

void MainController::startGame() {
}

