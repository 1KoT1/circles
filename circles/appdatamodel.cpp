#include "appdatamodel.h"

AppDataModel::AppDataModel(QObject *parent) :
	QObject(parent),
	mDisplay(Displays::MainMenu)
{

}

AppDataModel::~AppDataModel() {

}

Displays::DisplaysEnum AppDataModel::display() const {
	return mDisplay;
}

void AppDataModel::setDisplay(const Displays::DisplaysEnum display) {
	if(mDisplay != display) {
		mDisplay = display;
		emit displayChanged();
	}
}

