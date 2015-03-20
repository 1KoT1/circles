import QtQuick 2.0
import QtQuick.Particles 2.0

ParticleSystem {
    id: fire
    property double r: modelData.radius
    property int lifeTime: 1000

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

//    NumberAnimation on opacity {
//        to: 0
//        duration: 1000

//        onRunningChanged: {
//            if (!running) {
//                console.log("Destroying...")
//                fire.destroy();
//            }
//        }
//    }
}

