#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "appdatamodel.h"
#include <memory>
#include <QObject>
#include <QTimer>

class MainController : public QObject {
	Q_OBJECT
public:
	explicit MainController(AppDataModelPtr appDataModel, QObject *parent = 0);
	virtual ~MainController();

	Q_INVOKABLE void quit();
	Q_INVOKABLE void startGame();

signals:

public slots:
private:
	AppDataModelPtr mAppDataModel;
};

#endif // MAINCONTROLLER_H
