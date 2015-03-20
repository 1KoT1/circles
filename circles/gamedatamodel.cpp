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

const QList<CirclePtr> &GameDataModel::circles() const {
    return mCircles;
}

QList<QObject *> GameDataModel::circlesGUI() const {
    QList<QObject*> res;
    transform(mCircles.begin(), mCircles.end(), back_inserter(res), [](CirclePtr c){ return c.get(); });
    return res;
}

void GameDataModel::addCircle(CirclePtr circle) {
    mCircles.append(circle);
    emit circlesChanged();
}

void GameDataModel::removeCircle(CirclePtr circle) {
    if(mCircles.removeOne(circle)) {
        emit circlesChanged();
    }
}

void GameDataModel::clearCircle() {
    mCircles.clear();
    emit circlesChanged();
}

const QList<FlyingSpotPtr> &GameDataModel::spots() const {
    return mSpots;
}

QList<QObject *> GameDataModel::spotsGUI() const {
    QList<QObject*> res;
    transform(mSpots.begin(), mSpots.end(), back_inserter(res), [](FlyingSpotPtr c){ return c.get(); });
    return res;
}

void GameDataModel::addSpot(FlyingSpotPtr spot) {
    mSpots.append(spot);
    emit spotsChanged();
}

void GameDataModel::removeSpot(FlyingSpotPtr spot) {
    if(mSpots.removeOne(spot)) {
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
