import QtQuick 2.0

Rectangle {
    id: mainMenuBatton
    width: 100
    height: 23
    color: "#383296"
    border.color: "#000c72"
    radius: 4

    property string text: "Batton"
    signal clicked

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: mainMenuBatton.text
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
                color: "#7e79cb"
            }
        }
    ]
}

