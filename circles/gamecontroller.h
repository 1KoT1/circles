#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "gamedatamodel.h"
#include <memory>
#include <QObject>
#include <QSizeF>

class GameController : public QObject {
	Q_OBJECT
public:
	explicit GameController(GameDataModel *gameDataModel, qreal mRadiusOfCircles, long mLifeTimeOfCircles, uint mNumberOfSpots, double mSpeedOfSports, QObject *parent = 0);
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
	uint mNumberOfSpots;
	double mSpeedOfSports;

	bool spotIntersectCirkle(const QPointF &spotPosition) const;
};

#endif // GAMECONTROLLER_H
