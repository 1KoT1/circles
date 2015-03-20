#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "appdatamodel.h"
#include "gamecontroller.h"
#include <memory>
#include <QObject>
#include <QTimer>

class MainController : public QObject {
	Q_OBJECT
	Q_PROPERTY(QObject* gameController READ gameController NOTIFY gameControllerChanged)
public:
	explicit MainController(AppDataModelPtr appDataModel, QObject *parent = 0);
	virtual ~MainController();

	Q_INVOKABLE void quit();
	Q_INVOKABLE void startGame();

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
