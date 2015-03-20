import QtQuick 2.0
import QtQuick.Particles 2.0
import "fireControl.js" as FireControl

Rectangle {
    id: gameDiplay
    color: "black"

    property variant circles: appDataModel.gameDataModel.circles

    onCirclesChanged: FireControl.updateCircles(circles)

    MouseArea {
        anchors.fill: gameDiplay
        onClicked: mainController.gameController.createCircle(Qt.point(mouse.x, mouse.y))
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

