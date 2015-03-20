import QtQuick 2.0

Rectangle {
    id: mainMenuBatton
    border.color: "white"
    border.width: 2
    width: 100
    height: battonTitle.height + 8 + border.width
    color: "black"

    property string text: "Batton"
    signal clicked

    Text {
        id: battonTitle
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: mainMenuBatton.text
        color: "white"
    }

    MouseArea {
        anchors.fill: mainMenuBatton
        onPressed: mainMenuBatton.state = "Pressed"
        onReleased: mainMenuBatton.state = ""
        onClicked: mainMenuBatton.clicked()
    }

    states: [
        State {
            name: "Pressed"

            PropertyChanges {
                target: mainMenuBatton
                color: "orange"
            }
        }
    ]
}

