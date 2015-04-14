#include "gamedatamodel.h"
#include <algorithm>

using namespace std;

GameDataModel::GameDataModel(QObject *parent) :
	QObject(parent),
	mUserCreateCircle(false)
{

}

GameDataModel::~GameDataModel() {

}

const CirclesCollection &GameDataModel::circles() const {
	return mCircles;
}

QList<QObject *> GameDataModel::circlesGUI() const {
	QList<QObject*> res;
	transform(mCircles.begin(), mCircles.end(), back_inserter(res), [](CirclePtr c){ return c.get(); });
	return res;
}

void GameDataModel::addCircle(CirclePtr circle) {
	mCircles.push_back(circle);
	emit circlesChanged();
}

void GameDataModel::removeCircle(CirclePtr circle) {
	auto oldSize = mCircles.size();
	mCircles.remove(circle);
	if(mCircles.size() != oldSize) {
		emit circlesChanged();
	}
}

void GameDataModel::removeCircles(const std::function<bool(const CirclePtr &)> &p) {
	auto oldSize = mCircles.size();
	mCircles.remove_if(p);
	if(mCircles.size() != oldSize) {
		emit circlesChanged();
	}
}

void GameDataModel::clearCircle() {
	mCircles.clear();
	emit circlesChanged();
}

const FlyingSpotCollection &GameDataModel::spots() const {
	return mSpots;
}

QList<QObject *> GameDataModel::spotsGUI() const {
	QList<QObject*> res;
	transform(mSpots.begin(), mSpots.end(), back_inserter(res), [](FlyingSpotPtr c){ return c.get(); });
	return res;
}

void GameDataModel::addSpot(FlyingSpotPtr spot) {
	mSpots.push_back(spot);
	emit spotsChanged();
}

void GameDataModel::removeSpot(FlyingSpotPtr spot) {
	auto oldSize = mSpots.size();
	mSpots.remove(spot);
	if(mCircles.size() != oldSize) {
		emit spotsChanged();
	}
}

void GameDataModel::clearSport() {
	mSpots.clear();
	emit spotsChanged();
}

QDateTime GameDataModel::lastUpdateTime() const {
	return mLastUpdateTime;
}

void GameDataModel::setlastUpdateTime(const QDateTime &lastUpdateTime) {
	mLastUpdateTime = lastUpdateTime;
}

bool GameDataModel::userCreateCircle() const {
	return mUserCreateCircle;
}

void GameDataModel::setUserCreateCircle(bool userCreateCircle) {
	mUserCreateCircle = userCreateCircle;
}

const QSizeF &GameDataModel::gameAreaSize() const {
	return mGameAreaSize;
}

void GameDataModel::setGameAreaSize(const QSizeF &gameAreaSize) {
	mGameAreaSize = gameAreaSize;
}
