#ifndef CIRCLE_H
#define CIRCLE_H

#include <QDateTime>
#include <QObject>
#include <QPointF>

/** Класс хранящий данные "пузыря", врезавшись в который взрываются точки.
 */
class Circle : public QObject {
	Q_OBJECT
	Q_PROPERTY(QPointF center READ center WRITE setCenter NOTIFY centerChanged)
	Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)
public:
	/** "Пузырь", врезавшись в который взрываются точки.
	 *
	 * @param center Координаты центра "пузыря"
	 * @param radius Радиус "пузыря"
	 * @param timeOfCreation Время, когда "пузырь" был создан.
	 * @param parent Указатель на родителя в дереве Qt.
	 */
	Circle(const QPointF &center, qreal radius, QDateTime timeOfCreation, QObject *parent = 0);
	virtual ~Circle();

	/** Координаты центра "пузыря"
	 */
	const QPointF &center() const;
	/** Изменить координаты центра "пузыря"
	 * @param center Новые координаты центра "пузыря"
	 */
	void setCenter(const QPointF &center);

	/** Радиус "пузыря"
	 */
	qreal radius() const;
	/** Изменить радиус "пузыря"
	 * @param center Новый радиус "пузыря"
	 */
	void setRadius(qreal radius);

	/** Время, когда "пузырь" был создан.
	 */
	const QDateTime &timeOfCreation() const;
	/** Задать время, когда "пузырь" был создан.
	 * @param timeOfCreation Новое значение времени.
	 */
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
