import Circles 1.0
import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    visible: true
    width: 360
    height: 360

    Loader{
        anchors.fill: parent;
        source: appDataModel.display === Displays.Game? "GameDisplay.qml" : "MainMenu.qml";
    }
}
