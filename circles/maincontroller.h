#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "appdatamodel.h"
#include "gamecontroller.h"
#include <memory>
#include <QObject>
#include <QTimer>

/** Основной контроллер приложения
 */
class MainController : public QObject {
	Q_OBJECT
	Q_PROPERTY(QObject* gameController READ gameController NOTIFY gameControllerChanged)
public:
	/** Основной контроллер приложения
	 *
	 * @param appDataModel Указатель на модель данных приложения.
	 * @param parent Указатель на родителя в дереве Qt.
	 */
	explicit MainController(AppDataModelPtr appDataModel, QObject *parent = 0);
	virtual ~MainController();

	/** Выйти из приложения.
	 */
	Q_INVOKABLE void quit();
	/** Начать игру.
	 */
	Q_INVOKABLE void startGame();

	/** Содержит логику игры.
	 */
	GameController *gameController() const;
signals:
	void gameControllerChanged();

public slots:
private slots:
	void gameStopHandler();

private:
	AppDataModelPtr mAppDataModel;
	std::unique_ptr<GameController> mGameController;
	QTimer mTimer;
};

#endif // MAINCONTROLLER_H
