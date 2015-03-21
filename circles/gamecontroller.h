#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "gamedatamodel.h"
#include <memory>
#include <QObject>
#include <QSizeF>

const double defaultRadiusOfCircles = 50;
const int defaultLifeTimeOfCircles = 5 * 1000;
const int defaultTimeOfCircleBurn = 500;
const uint defaultNumberOfSpots = 10;
const double defaultSpeedOfSports = 60;
const int udateSceneInterval = 1000 / 25;

class GameController : public QObject {
	Q_OBJECT
public:
	explicit GameController(GameDataModel *gameDataModel, qreal mRadiusOfCircles, long mLifeTimeOfCircles, long timeOfCircleBurn, uint mNumberOfSpots, double mSpeedOfSports, QObject *parent = 0);
	virtual ~GameController();

	void initGame();

	Q_INVOKABLE void createCircle(const QPointF &position);
	Q_INVOKABLE void setGameAreaSize(int width, int height);
	Q_INVOKABLE void stopGame();

signals:
	void gameStoped();

public slots:
	void updateScene();

private:
	GameDataModel* mGameDataModel;
	qreal mRadiusOfCircles;
	/** Время жизни круга в милисекундах.*/
	long mLifeTimeOfCircles;
	/** Время в течении которогокруг растёт. В милисекундах.*/
	long mTimeOfCircleBurn;
	uint mNumberOfSpots;
	double mSpeedOfSports;
	/** Скорость роста круга. Чтобы не пересчитывать многократно, сохраняю значение заранее.*/
	double mSpeeOfCircleBurn;

	bool spotIntersectCirkle(const QPointF &spotPosition) const;
};

#endif // GAMECONTROLLER_H
