#include "appdatamodel.h"
#include "maincontroller.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;		
		AppDataModelPtr dm(new AppDataModel());
		engine.rootContext()->setContextProperty("appDataModel", dm.get());
		MainController mc(dm);
		engine.rootContext()->setContextProperty("mainController", &mc);
		Displays::declareQML();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
