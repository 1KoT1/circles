import QtQuick 2.0

Rectangle {
    id: gameDiplay
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#1b74ff"
        }

        GradientStop {
            position: 1
            color: "#a9c9fa"
        }
    }

    MouseArea {
        anchors.fill: gameDiplay
        onClicked: mainController.gameController.createCircle(Qt.point(mouse.x, mouse.y))
    }

    Repeater {
        model: appDataModel.gameDataModel.circles
        delegate: Image {
            source: "bubble.svg"
            property double r: modelData.radius
            x: modelData.center.x - r
            y: modelData.center.y - r
            height: r * 2;
            width: height
        }
    }

    Repeater {
        model: appDataModel.gameDataModel.spots
        delegate: Image {
            source: "bubble.svg"
            property double r: 5
            x: modelData.position.x - r
            y: modelData.position.y - r
            height: r * 2;
            width: height
        }
    }
}

