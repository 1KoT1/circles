#ifndef FLYINGSPOT_H
#define FLYINGSPOT_H

#include <QObject>
#include <QPointF>

/** Класс хранящий данные точек, латющих посцене игры.
 */
class FlyingSpot : public QObject {
	Q_OBJECT
	Q_PROPERTY(QPointF position READ position WRITE setPosition NOTIFY positionChanged)
public:
	/** Класс хранящий данные точек, латющих посцене игры.
	 *
	 * @param position Текущие координаты точки.
	 * @param speed Вектор скорости точки.
	 * @param parent Указатель на родителя в дереве Qt.
	 */
	FlyingSpot(const QPointF &position, const QPointF &speed, QObject *parent = 0);
	virtual ~FlyingSpot();

	/** Текущие координаты точки.
	 */
	const QPointF &position() const;
	/** Изменить координаты точки.
	 * @param position Новые координаты точки.
	 */
	void setPosition(const QPointF &position);

	/** Вектор скорости точки.
	 */
	const QPointF &speed() const;
	/** Изменить вектор скорости точки.
	 * @param speed Новое значение скорости.
	 */
	void setSpeed(const QPointF &speed);
signals:
	void positionChanged();

public slots:
private:
	QPointF mPosition;
	QPointF mSpeed;
};

#endif // FLYINGSPOT_H
