#ifndef APPDATAMODEL_H
#define APPDATAMODEL_H

#include <memory>
#include <QObject>
#include <QtQml>

class Displays : public QObject {
	Q_OBJECT
public:
	enum DisplaysEnum {
		MainMenu,
		Game
	};
	Q_ENUMS(DisplaysEnum)

	static void declareQML() {
		qmlRegisterType<Displays>("Circles", 1, 0, "Displays");
	}
};

class AppDataModel : public QObject {
	Q_OBJECT
	Q_PROPERTY(Displays::DisplaysEnum display READ display WRITE setDisplay NOTIFY displayChanged)
public:
	explicit AppDataModel(QObject *parent = 0);
	virtual ~AppDataModel();

	Displays::DisplaysEnum display() const;
	void setDisplay(const Displays::DisplaysEnum display);
signals:
	void displayChanged();

public slots:
private:
	Displays::DisplaysEnum mDisplay;
};

using AppDataModelPtr = std::shared_ptr<AppDataModel>;

#endif // APPDATAMODEL_H
