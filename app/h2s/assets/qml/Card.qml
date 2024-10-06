import QtQuick 2.14
import QtQuick.Controls 2.14

Button {
    width: 30
    height: 49
    property var info
    property bool flip: info.flip
    property int cardId: info.cardId
    property var image: info.image

    Component.onCompleted: {
        img.source = info.image
    }

    Image {
        id: img
        width: parent.width
        height: parent.height
        fillMode: Image.PreserveAspectFit
        source: "qrc:/c120/back.png"
    }

    onImageChanged: {
        img.source = info.image
    }

    background: Rectangle {
        color: "transparent"
        anchors.fill: parent
//        border.color: checked ? "red" : "transparent"
        border.color: "transparent"
    }

}



