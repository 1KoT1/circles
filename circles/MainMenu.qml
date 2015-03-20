import QtQuick 2.4

Rectangle {
    id: mainMenu

    color: "black"

    Repeater {
        id: fires
        model: 5
        delegate: Fire {
            x: Math.random() * mainMenu.width
            y: Math.random() * mainMenu.height
            r: 50
        }
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 2

        MainMenuBatton {
            width: mainMenu.width
            text: qsTr("Начать игру")
            onClicked: mainController.startGame();
        }

        MainMenuBatton {
            width: mainMenu.width
            text: qsTr("Выйти")
            onClicked: mainController.quit();
        }
    }
}

