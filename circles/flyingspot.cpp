#include "flyingspot.h"

FlyingSpot::FlyingSpot(const QPointF &position, const QPointF &speed, QObject *parent) :
	QObject(parent),
	mPosition(position),
	mSpeed(speed)
{

}

FlyingSpot::~FlyingSpot()
{

}

const QPointF &FlyingSpot::position() const {
	return mPosition;
}

void FlyingSpot::setPosition(const QPointF &position) {
	if(mPosition != position){
		mPosition = position;
		emit positionChanged();
	}
}

const QPointF &FlyingSpot::speed() const{
	return mSpeed;
}

void FlyingSpot::setSpeed(const QPointF &speed) {
	mSpeed = speed;
}

