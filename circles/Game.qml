import QtQuick 2.0
import QtQuick.Particles 2.0

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
        delegate: ParticleSystem {
            property double r: modelData.radius
            x: modelData.center.x
            y: modelData.center.y

            Emitter {
                id: fireEmitter
                velocity: AngleDirection {
                    angleVariation: 360
                    magnitudeVariation: 10
                    magnitude: r - magnitudeVariation
                }
                lifeSpan: 1000
                emitRate: 1000
            }

            ImageParticle {
                source: "particleA.png"
                color: "Orange"
            }
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

