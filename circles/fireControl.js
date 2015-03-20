var component;
var fires = [];

function updateCircles(circles) {
    if(circles.length > fires.length) {
        for(var i = fires.length; i < circles.length; i++) {
            createFire(circles[i])
        }
    } else {
        for(var i = circles.length; i < fires.length; i++) {
            fires[i].destroy();
        }
    }
}

function createFire(circle) {
    component = Qt.createComponent("Fire.qml");
    fires[circle.center] = component.createObject(gameDiplay, {"x": circle.center.x, "y": circle.center.y, "r": circle.radius});

    if (fires[circle.center] === null) {
        console.error(qsTr("Ошибка создания объекта"));
    }
}
