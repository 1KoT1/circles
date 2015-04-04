import QtQuick 2.0

Item {
    id: updatableRepeater
    property int count
    property Component delegate
    property variant model

    signal itemAdded(int index, Item item)
    signal itemRemoved(int index, Item item)

    property variant dataKeys: []
    onModelChanged: {
        console.debug(qsTr("Обновилась модель."));
        if(model === null) {
            console.debug(qsTr("Модель пустая."));
            return;
        }

        if(delegate === null) {
            console.debug(qsTr("Делегат не задан."));
            return;
        }

        for(var j = 0; j < children.length; j++) {
            var needRemove = true;
            for(var k = 0; k < model.length; k++) {
                if(dataKeys[j] === model[k]) {
                    needRemove = false;
                    break;
                }
            }
            if(needRemove) {
                console.debug(qsTr("Удаляю экземпляр делегата."));
                children[j].destroy()
                dataKeys.splice(j, 1);
            }
        }

        for(var i = 0; i < model.length; i++) {
            var needCreate = true;
            for(var n = 0; n < dataKeys.length; n++) {
                if(dataKeys[n] === model[i]) {
                    needCreate = false;
                    break;
                }
            }

            if(needCreate) {
                console.debug(qsTr("Создаю экземпляр делегата."));
                var newObj = delegate.createObject(updatableRepeater, {"modelData": Qt.binding(function() { return model[i]; })});

                if (newObj === null) {
                    console.error(qsTr("Ошибка создания объекта."));
                } else {
                    dataKeys.push(model[i]);
                    itemAdded(i, newObj);
                }
            }
        }

        count = children.length;
        console.debug(qsTr("Количество элементов: %1 %2").arg(children.length).arg(dataKeys.length));
    }
}

