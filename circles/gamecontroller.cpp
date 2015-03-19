#include <algorithm>
#include "gamecontroller.h"
#include <math.h>
#include <random>

const double PI = 3.14159265358979323846;

using namespace std;

GameController::GameController(GameDataModelPtr gameDataModel, qreal radiusOfCircles, long lifeTimeOfCircles, uint numberOfSpots, double speedOfSports, QSizeF gameAreaSize, QObject *parent) :
	QObject(parent),
	mGameDataModel(gameDataModel),
	mRadiusOfCircles(radiusOfCircles),
	mLifeTimeOfCircles(lifeTimeOfCircles),
	mNumberOfSpots(numberOfSpots),
	mSpeedOfSports(speedOfSports),
	mGameAreaSize(gameAreaSize)
{
	default_random_engine generator;
	uniform_real_distribution<qreal> distributionH(0, mGameAreaSize.width());
	uniform_real_distribution<qreal> distributionV(0, mGameAreaSize.height());
	uniform_real_distribution<qreal> distributionAngle(0, 2 * PI);
	for(uint i = 0; i < mNumberOfSpots; i++){
		double angle = distributionAngle(generator);
		mGameDataModel->addSpot(FlyingSpotPtr(new FlyingSpot(QPointF(distributionH(generator), distributionV(generator)),
																												 QPointF(cos(angle)*mSpeedOfSports, sin(angle)*mSpeedOfSports)
																												 )));
	}
	mGameDataModel->setlastUpdateTime(QDateTime::currentDateTime());
}

GameController::~GameController() {

}

void GameController::updateScene() {
}

void GameController::createCircle(const QPointF &position) {
	if(mGameDataModel->circles().isEmpty()) {
		mGameDataModel->addCircle(CirclePtr(new Circle(position, mRadiusOfCircles, QDateTime::currentDateTime())));
	}
}

