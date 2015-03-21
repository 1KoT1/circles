#include <algorithm>
#include "gamecontroller.h"
#include <math.h>
#include <random>

const double PI = 3.14159265358979323846;

using namespace std;

GameController::GameController(GameDataModel* gameDataModel, qreal radiusOfCircles, long lifeTimeOfCircles, long timeOfCircleBurn, uint numberOfSpots, double speedOfSports, QObject *parent) :
	QObject(parent),
	mGameDataModel(gameDataModel),
	mRadiusOfCircles(radiusOfCircles),
	mLifeTimeOfCircles(lifeTimeOfCircles),
	mTimeOfCircleBurn(timeOfCircleBurn),
	mNumberOfSpots(numberOfSpots),
	mSpeedOfSports(speedOfSports),
	mSpeeOfCircleBurn(mRadiusOfCircles / mTimeOfCircleBurn)
{
}

GameController::~GameController() {

}

void GameController::updateScene() {
	auto curTime = QDateTime::currentDateTime();
	auto deltaTime = mGameDataModel->lastUpdateTime().msecsTo(curTime);
	mGameDataModel->setlastUpdateTime(curTime);

	for(auto circle: mGameDataModel->circles()) {
		if ( circle->timeOfCreation().msecsTo(curTime) >= mLifeTimeOfCircles + mTimeOfCircleBurn ) {
			mGameDataModel->removeCircle(circle);
		} else if ( circle->timeOfCreation().msecsTo(curTime) >= mLifeTimeOfCircles &&
								circle->radius() != mRadiusOfCircles)
		{
			circle->setRadius(mRadiusOfCircles);
		} else {
			circle->setRadius(mSpeeOfCircleBurn * deltaTime );
		}
	}

	if(mGameDataModel->userCreateCircle() && mGameDataModel->circles().isEmpty()) {
		stopGame();
	}

	auto gameAreaSize = mGameDataModel->gameAreaSize();
	for(auto spot: mGameDataModel->spots()) {
		auto newPosition = spot->position() + spot->speed() * (deltaTime / 1000.0);
		if(newPosition.x() < 0) {
			newPosition.setX(0 - newPosition.x());
			spot->setSpeed(QPointF(-spot->speed().x(), spot->speed().y()));
		}
		if(newPosition.y() < 0) {
			newPosition.setY(0 - newPosition.y());
			spot->setSpeed(QPointF(spot->speed().x(), -spot->speed().y()));
		}
		if(newPosition.x() > gameAreaSize.width()) {
			newPosition.setX(gameAreaSize.width() - (newPosition.x() - gameAreaSize.width()));
			spot->setSpeed(QPointF(-spot->speed().x(), spot->speed().y()));
		}
		if(newPosition.y() > gameAreaSize.height()) {
			newPosition.setY(gameAreaSize.height() - (newPosition.y() - gameAreaSize.height()));
			spot->setSpeed(QPointF(spot->speed().x(), -spot->speed().y()));
		}

		if(spotIntersectCirkle(newPosition)) {
			mGameDataModel->removeSpot(spot);
			mGameDataModel->addCircle(CirclePtr(new Circle(newPosition, baseRadiusOfCircle, curTime)));
		} else {
			spot->setPosition(newPosition);
		}
	}
}

void GameController::initGame() {
	mGameDataModel->setUserCreateCircle(false);
	mGameDataModel->clearCircle();
	mGameDataModel->clearSport();

	default_random_engine generator;
	uniform_real_distribution<qreal> distributionH(0, mGameDataModel->gameAreaSize().width());
	uniform_real_distribution<qreal> distributionV(0, mGameDataModel->gameAreaSize().height());
	uniform_real_distribution<qreal> distributionAngle(0, 2 * PI);
	for(uint i = 0; i < mNumberOfSpots; i++){
		double angle = distributionAngle(generator);
		mGameDataModel->addSpot(FlyingSpotPtr(new FlyingSpot(QPointF(distributionH(generator), distributionV(generator)),
																												 QPointF(cos(angle)*mSpeedOfSports, sin(angle)*mSpeedOfSports)
																												 )));
	}

	mGameDataModel->setlastUpdateTime(QDateTime::currentDateTime());
}

bool GameController::spotIntersectCirkle(const QPointF &spotPosition) const {
	return any_of(mGameDataModel->circles().begin(), mGameDataModel->circles().end(),
								[&](CirclePtr c) {
		auto d = c->center() - spotPosition;
		return sqrt(pow(d.x(), 2) + pow(d.y(), 2)) <= c->radius();
	});
}

void GameController::stopGame() {
	emit gameStoped();
}

void GameController::createCircle(const QPointF &position) {
	if(!mGameDataModel->userCreateCircle()) {
		mGameDataModel->addCircle(CirclePtr(new Circle(position, baseRadiusOfCircle, QDateTime::currentDateTime())));
		mGameDataModel->setUserCreateCircle(true);
	}
}

void GameController::setGameAreaSize(int width, int height) {
	mGameDataModel->setGameAreaSize(QSizeF(width, height));
}

