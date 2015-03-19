import QtQuick 2.4

Rectangle {
    id: mainMenu

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 2

        MainMenuBatton {
            text: qsTr("Начать игру")
            onClicked: mainController.startGame();
        }

        MainMenuBatton {
            text: qsTr("Выйти")
            onClicked: mainController.quit();
        }
    }
}

