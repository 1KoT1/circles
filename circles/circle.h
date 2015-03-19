#ifndef CIRCLE_H
#define CIRCLE_H

#include <QDateTime>
#include <QObject>
#include <QPointF>

class Circle : public QObject {
	Q_OBJECT
	Q_PROPERTY(QPointF center READ center WRITE setCenter NOTIFY centerChanged)
	Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)
public:
	Circle(const QPointF &center, qreal radius, QDateTime timeOfCreation, QObject *parent = 0);
	virtual ~Circle();

	const QPointF &center() const;
	void setCenter(const QPointF &center);
	qreal radius() const;
	void setRadius(qreal radius);
	const QDateTime &timeOfCreation() const;
	void setTimeOfCreation(const QDateTime &timeOfCreation);

signals:
	void centerChanged();
	void radiusChanged();

public slots:
private:
	QPointF mCenter;
	qreal mRadius;
	QDateTime mTimeOfCreation;
};

#endif // CIRCLE_H
