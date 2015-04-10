#ifndef GAMEDATAMODEL_H
#define GAMEDATAMODEL_H

#include "circle.h"
#include "flyingspot.h"
#include <list>
#include <memory>
#include <QObject>
#include <QSizeF>

using CirclePtr = std::shared_ptr<Circle>;
using CirclesCollection = std::list<CirclePtr>;
using FlyingSpotPtr = std::shared_ptr<FlyingSpot>;

/** Модель данных игры
 */
class GameDataModel : public QObject {
	Q_OBJECT
	Q_PROPERTY(QList<QObject*> circles READ circlesGUI NOTIFY circlesChanged)
	Q_PROPERTY(QList<QObject*> spots READ spotsGUI NOTIFY spotsChanged)
public:
	explicit GameDataModel(QObject *parent=0);
	virtual ~GameDataModel();

	/** Сущствующие "пузыри"
	 */
	const CirclesCollection &circles() const;
	/** Список указателей на "пузыри" для передачи в QML.
	 */
	QList<QObject*> circlesGUI() const;
	/** Добавить новый "пузырь"
	 *
	 * @param circle Объект, который надо добавить.
	 */
	void addCircle(CirclePtr circle);
	/** Уничтожить"пузырь"
	 *
	 * @param circle Указатель на "пузырь", который надо уничтожить.
	 */
	void removeCircle(CirclePtr circle);
	/** Уничтожить все "пузыри"
	 */
	void clearCircle();

	/** Сущствующие точки
	 */
	const QList<FlyingSpotPtr> &spots() const;
	/** Список указателей на точкки для передачи в QML.
	 */
	QList<QObject*>spotsGUI() const;
	/** Добавить новую точку.
	 *
	 * @param circle Объект, который надо добавить.
	 */
	void addSpot(FlyingSpotPtr spot);
	/** Уничтожить точку.
	 *
	 * @param circle Указатель на точку, которую надо уничтожить.
	 */
	void removeSpot(FlyingSpotPtr spot);
	/** Уничтожить все точки.
	 */
	void clearSport();

	/** Время, когда последний раз пересчитывались данные.
	 */
	QDateTime lastUpdateTime() const;
	/** Сохранить время, когда последний раз пересчитывались данные.
	 *
	 * @param lastUpdateTime
	 */
	void setlastUpdateTime(const QDateTime &lastUpdateTime);

	/** Пользователь уже создал первый "пузырь"
	 */
	bool userCreateCircle() const;
	/** Указать, что пользователь уже создал первый "пузырь"
	 */
	void setUserCreateCircle(bool userCreateCircle);

	/** Размер зоны игры.
	 */
	const QSizeF &gameAreaSize() const;
	void setGameAreaSize(const QSizeF &gameAreaSize);
signals:
	void circlesChanged();
	void spotsChanged();
private:
	CirclesCollection mCircles;
	QList<FlyingSpotPtr> mSpots;
	QDateTime mLastUpdateTime;
	bool mUserCreateCircle;
	QSizeF mGameAreaSize;
};

#endif // GAMEDATAMODEL_H
