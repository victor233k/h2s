import QtQuick 2.14
import QtQuick.Controls 2.14


Page {
    title: qsTr("Card Pick")

    GridView {
        id: gridView
        anchors.fill: parent
        anchors.centerIn: parent
//        anchors.margins: 5
        cellWidth: 59
        cellHeight: 120

        flow: GridView.FlowLeftToRight
//        flow: GridView.FlowTopToBottom
        height: cellHeight*13
        model: 52
//        model: images.length
        delegate: Item {
            width: gridView.cellWidth
            height: gridView.cellHeight

            Image {
//                anchors.margins: 5
                anchors.fill: parent
                source: bizCommand.getCardImage(index)
                fillMode: Image.PreserveAspectFit
                asynchronous: true
            }
        }


    }

    function getImagePath(index) {

        // 检查索引是否在有效范围内
        if (index >= 0 && index < images.length) {
            return images[index];
        } else {
            console.warn("Index out of range: " + index);
            return "qrc:/c120/back.png"; // 返回一个默认图片路径
        }
    }
}

