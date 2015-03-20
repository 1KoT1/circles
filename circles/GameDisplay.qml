import QtQuick 2.4

Rectangle {
    id: gameDisplay

    Game {
        anchors.left: gameDisplay.left
        anchors.top: gameDisplay.top
        anchors.right: gameDisplay.right
        anchors.bottom: gameStopBatton.top
    }

    Rectangle {
        id: gameStopBatton
        border.width: 2
        border.color: "white"
        anchors.left: gameDisplay.left
        anchors.bottom: gameDisplay.bottom
        anchors.right: gameDisplay.right
        height: gameStopBattonTitle.font.pixelSize + 8 + border.width
        color: "black"

        Text {
            id: gameStopBattonTitle
            anchors.horizontalCenter: gameStopBatton.horizontalCenter
            anchors.verticalCenter: gameStopBatton.verticalCenter
            text: qsTr("Закончить игру")
            color: "white"
        }

        MouseArea {
            anchors.fill: gameStopBatton
            onClicked: mainController.gameController.stopGame()
        }
    }
}

