import QtQuick 2.0

Item {
    id: updatableRepeater
    property int count
    property Component delegate
    property variant model

    signal itemAdded(int index, Item item)
    signal itemRemoved(int index, Item item)

    property list dataKeys
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
            //            console.debug(qsTr("modelData %1").arg(delegate.modelData));
        }

        for(var i = 0; i < model.length; i++) {
            var newObj = delegate.createObject(updatableRepeater, {"modelData": Qt.binding(function() { return model[i]; })});

            if (newObj === null) {
                console.error(qsTr("Ошибка создания объекта."));
            } else {
                //                resources.add("jjiii");
                dataKeys.add(model[i])
                itemAdded(i, newObj);
            }
        }

        count = children.length;
        console.debug(qsTr("Количество элементов: %1 %2 %3").arg(children.length).arg(resources.length).arg(dataKeys.length));
    }
}

