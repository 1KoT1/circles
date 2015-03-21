var component;
var fires = [];

function updateCircles(circles) {
    if(component === undefined) {
        component = Qt.createComponent("Fire.qml");
    }
    if(circles.length > fires.length) {
        for(var i = fires.length; i < circles.length; i++) {
            createFire(circles[i]);
        }
    } else {
        while(fires.length > circles.length) {
            var fire = fires.shift();
            fire.destroy();
        }
    }
}

function createFire(circle) {
    fires.push(component.createObject(gameDiplay, {"x": circle.center.x, "y": circle.center.y, "r": Qt.binding(function() { return circle.radius; })}));

    if (fires[fires.length - 1] === null) {
        console.error(qsTr("Ошибка создания объекта"));
    }
}
