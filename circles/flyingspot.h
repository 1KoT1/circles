#ifndef FLYINGSPOT_H
#define FLYINGSPOT_H

#include <QObject>
#include <QPointF>

class FlyingSpot : public QObject {
	Q_OBJECT
	Q_PROPERTY(QPointF position READ position WRITE setPosition NOTIFY positionChanged)
public:
	explicit FlyingSpot(QObject *parent = 0);
	FlyingSpot(const QPointF &position, const QPointF &speed, QObject *parent = 0);
	virtual ~FlyingSpot();

	const QPointF &position() const;
	void setPosition(const QPointF &position);
	const QPointF &speed() const;
	void setSpeed(const QPointF &speed);
signals:
	void positionChanged();

public slots:
private:
	QPointF mPosition;
	QPointF mSpeed;
};

#endif // FLYINGSPOT_H
