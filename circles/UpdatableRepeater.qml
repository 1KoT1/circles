import QtQuick 2.0

Item {
    id: updatableRepeater
    property int count
    property Component delegate
    property variant model

    signal itemAdded(int index, Item item)
    signal itemRemoved(int index, Item item)

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

//        for(var modelItemIndex = 0; modelItemIndex < model.length; modelItemIndex++) {
//            console.debug(model[modelItemIndex].toString());
//        }

        for(var delegateIndex = 0; delegateIndex < children.length; delegateIndex++) {
            var needRemove = true;
            for(var modelIndex = 0; modelIndex < model.length; modelIndex++) {
                if(children[delegateIndex].objectName === model[modelIndex].toString()) {
                    needRemove = false;
                    break;
                }
            }
            if(needRemove) {
                console.debug(qsTr("Удаляю экземпляр делегата."));
                console.debug(qsTr("____Количество делегатов: %1").arg(children.length));
                children[delegateIndex].destroy();
                console.debug(qsTr("____Количество делегатов: %1").arg(children.length));
            }
        }

        for(var modelItemIndex = 0; modelItemIndex < model.length; modelItemIndex++) {
            var needCreate = true;
            for(var delegateIndex = 0; delegateIndex < children.length; delegateIndex++) {
                if(children[delegateIndex].objectName === model[modelItemIndex].toString()) {
                    needCreate = false;
                    break;
                }
            }

            if(needCreate) {
                console.debug(qsTr("Создаю экземпляр делегата."));
                var newObj = delegate.createObject(updatableRepeater, {"objectName": model[modelItemIndex].toString(), "modelData": Qt.binding(function() { return model[modelItemIndex]; })});

                if (newObj === null) {
                    console.error(qsTr("Ошибка создания объекта."));
                } else {
                    itemAdded(modelItemIndex, newObj);
//                    console.debug(qsTr("Создан делегат с id: %1").arg(children[children.length - 1].objectName));
                }
            }
        }

        count = children.length;
        console.debug(qsTr("Количество элементов: %1").arg(children.length));
    }
}

