#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "gamedatamodel.h"
#include <memory>
#include <QObject>
#include <QSizeF>

class GameController : public QObject {
	Q_OBJECT
public:
	explicit GameController(GameDataModelPtr gameDataModel, qreal mRadiusOfCircles, long mLifeTimeOfCircles, uint mNumberOfSpots, double mSpeedOfSports, QSizeF gameAreaSize, QObject *parent = 0);
	virtual ~GameController();

	Q_INVOKABLE void createCircle(const QPointF &position);

signals:

public slots:
	void updateScene();

private:
	GameDataModelPtr mGameDataModel;
	qreal mRadiusOfCircles;
	/** Время жизни круга в милисекундах.*/
	long mLifeTimeOfCircles;
	uint mNumberOfSpots;
	double mSpeedOfSports;
	QSizeF mGameAreaSize;
};

#endif // GAMECONTROLLER_H