import QtQuick 2.0
import QtQuick.Particles 2.0

Rectangle {
    id: gameDiplay
    color: "black"

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
        delegate: ParticleSystem {
            property double r: 7
            x: modelData.position.x
            y: modelData.position.y

            Emitter {
                velocity: AngleDirection {
                    angleVariation: 360
                    magnitudeVariation: r
                }
                lifeSpan: 1000
                emitRate: 5
            }

            ImageParticle {
                source: "spot.png"
            }
        }
    }
}

