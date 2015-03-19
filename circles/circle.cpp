#include "circle.h"

Circle::Circle(const QPointF &center, qreal radius, QDateTime timeOfCreation, QObject *parent) :
	QObject(parent),
	mCenter(center),
	mRadius(radius),
	mTimeOfCreation(timeOfCreation)
{

}

Circle::~Circle() {

}

const QPointF &Circle::center() const {
	return mCenter;
}

void Circle::setCenter(const QPointF &center) {
	if(mCenter != center) {
		mCenter = center;
		emit centerChanged();
	}
}

qreal Circle::radius() const{
	return mRadius;
}

void Circle::setRadius(qreal radius) {
	if(mRadius != radius) {
		mRadius = radius;
		emit radiusChanged();
	}
}

const QDateTime &Circle::timeOfCreation() const {
	return mTimeOfCreation;
}

void Circle::setTimeOfCreation(const QDateTime &timeOfCreation) {
	mTimeOfCreation = timeOfCreation;
}

