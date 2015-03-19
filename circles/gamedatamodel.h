#ifndef GAMEDATAMODEL_H
#define GAMEDATAMODEL_H

#include "circle.h"
#include "flyingspot.h"
#include <memory>
#include <QObject>

using CirclePtr = std::shared_ptr<Circle>;
using FlyingSpotPtr = std::shared_ptr<FlyingSpot>;

class GameDataModel : public QObject {
	Q_OBJECT
	Q_PROPERTY(QList<QObject*> circles READ circlesGUI NOTIFY circlesChanged)
	Q_PROPERTY(QList<QObject*> spots READ spotsGUI NOTIFY spotsChanged)
public:
	explicit GameDataModel(QObject *parent=0);
	virtual ~GameDataModel();

	const QList<CirclePtr> &circles() const;
	QList<QObject*> circlesGUI() const;
	void addCircle(CirclePtr circle);
	void removeCircle(CirclePtr circle);
	const QList<FlyingSpotPtr> &spots() const;
	QList<QObject*>spotsGUI() const;
	void addSpot(FlyingSpotPtr spot);
	void removeSpot(FlyingSpotPtr spot);
	QDateTime lastUpdateTime() const;
	void setlastUpdateTime(const QDateTime &lastUpdateTime);
signals:
	void circlesChanged();
	void spotsChanged();
private:
	QList<CirclePtr> mCircles;
	QList<FlyingSpotPtr> mSpots;	
	QDateTime mLastUpdateTime;
};

using GameDataModelPtr = std::shared_ptr<GameDataModel>;

#endif // GAMEDATAMODEL_H
