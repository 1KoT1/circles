#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "gamedatamodel.h"
#include <memory>
#include <QObject>
#include <QSizeF>

/** Значение по умолчанию радиуса "пузырей"
 */
const double defaultRadiusOfCircles = 50;
/** Значение по умолчанию времени жизни "пузыря"
 */
const int defaultLifeTimeOfCircles = 5 * 1000;
/** Значение по умолчанию времени роста "пузыря"
 */
const int defaultTimeOfCircleBurn = 500;
/** Значение по умолчанию количества летящих точек.
 */
const uint defaultNumberOfSpots = 10;
/** Значение по умолчанию скорости летящих точек.
 */
const double defaultSpeedOfSports = 60;
/** Как часто обновлять цсену игры.
 */
const int udateSceneInterval = 1000 / 25;

/** Начальное значение радиуса "пузыря". С нго он будет рости до своего нормального радиуса.
 */
const double baseRadiusOfCircle = 0;

/** Содержит логику игры.
 */
class GameController : public QObject {
	Q_OBJECT
public:
	/** Содержит логику игры.
	 *
	 * У всех "пузырей" радиус одинаковый.
	 * У всех летающих точек одинаковая скорость.
	 *
	 * @param gameDataModel Указаель на модель данных игры. Контроллер расчитывает, что экземпляр модели данных существуе, пока существует контроллер.
	 * @param mRadiusOfCircles Иницирует раздиусь"пузырей"
	 * @param mLifeTimeOfCircles Инициирует время жизни "пузырей"
	 * @param timeOfCircleBurn Инициирует время роста "пузырей"
	 * @param mNumberOfSpots Инициирует количество летающих точек.
	 * @param mSpeedOfSports  Инициирует скорость летающих точек.
	 * @param parent Указатель на родителя в дереве Qt.
	 */
	explicit GameController(GameDataModel *gameDataModel, qreal mRadiusOfCircles, long mLifeTimeOfCircles, long timeOfCircleBurn, uint mNumberOfSpots, double mSpeedOfSports, QObject *parent = 0);
	virtual ~GameController();

	/** Инициировать игру
	 *
	 * Сбрасывает модель данных игры в начальные значения.
	 * У всех "пузырей" радиус одинаковый.
	 * У всех летающих точек одинаковая скорость.
	 */
	void initGame();

	/** Пользователь создаёт "пузырь"
	 *
	 * "Пузырь" будет создан только впервый раз.
	 * В последующие разы контроллер проигнорирует вызов метода.
	 * @param position Координаты, в которых пытаемся создать пузырь.
	 */
	Q_INVOKABLE void createCircle(const QPointF &position);
	/** Изменить размер области игры.
	 * @param width Новая ширина области игры.
	 * @param height Новая высота области игры.
	 */
	Q_INVOKABLE void setGameAreaSize(int width, int height);
	/** Оставновить игру.
	 */
	Q_INVOKABLE void stopGame();

signals:
	void gameStoped();

public slots:
	/** Пересчитать данные игры согласно прошедьшему времени.
	 */
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

	/** Проверить, влетела ли точка в какой ни будь "пузырь".
	 *
	 * @param spotPosition Позиция точки.
	 * @return true, если точка влетела в какой ни будь "пузырь". Иначе false.
	 */
	bool spotIntersectCircle(const QPointF &spotPosition) const;
};

#endif // GAMECONTROLLER_H
