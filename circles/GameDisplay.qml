import QtQuick 2.4

Rectangle {
    id: gameDisplay

    Game {
        anchors.left: gameDisplay.left
        anchors.top: gameDisplay.top
        anchors.right: gameDisplay.right
        anchors.bottom: gameStopBatton.top
    }

    MainMenuBatton {
        id: gameStopBatton
        anchors.left: gameDisplay.left
        anchors.bottom: gameDisplay.bottom
        anchors.right: gameDisplay.right
        text: qsTr("Закончить игру")
        onClicked: mainController.gameController.stopGame();
    }
}

