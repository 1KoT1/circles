#ifndef APPDATAMODEL_H
#define APPDATAMODEL_H

#include "gamedatamodel.h"
#include <memory>
#include <QObject>
#include <QtQml>

/** Перечисление указывающее возможные сцены приложения.
 */
class Displays : public QObject {
	Q_OBJECT
public:
	enum DisplaysEnum {
		MainMenu,
		Game
	};
	Q_ENUMS(DisplaysEnum)

	/** Зарегистрировать перечисление в QML.
	 */
	static void declareQML() {
		qmlRegisterType<Displays>("Circles", 1, 0, "Displays");
	}
};

/** Основная модельданных приложения.
 */
class AppDataModel : public QObject {
	Q_OBJECT
	Q_PROPERTY(Displays::DisplaysEnum display READ display WRITE setDisplay NOTIFY displayChanged)
	Q_PROPERTY(QObject* gameDataModel READ gameDataModel NOTIFY gameDataModelChanged)
public:
	explicit AppDataModel(QObject *parent = 0);
	virtual ~AppDataModel();

	/** Сцена отображаемая в данный момент.
	 */
	Displays::DisplaysEnum display() const;

	/** Изменить сцену отображаемую в данный момент
	 * @param display Новая сцена, к которой перейти.
	 */
	void setDisplay(const Displays::DisplaysEnum display);

	/** Модель данных игры.
	 *
	 * @return Указатель на объект модели данных игры. Объект существует, пока существует экземпляр AppDataModel
	 */
	GameDataModel *gameDataModel();
signals:
	void displayChanged();
	void gameDataModelChanged();

public slots:
private:
	Displays::DisplaysEnum mDisplay;
	GameDataModel mGameDataModel;
};

using AppDataModelPtr = std::shared_ptr<AppDataModel>;

#endif // APPDATAMODEL_H
