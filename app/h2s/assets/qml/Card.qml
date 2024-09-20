import QtQuick 2.0

Item {

    width: 64
    height: 64
    Image {
        id: myImage
        anchors.fill: parent
//        source: "file://PNG/Cards(large)/card_clubs_02.png"
        source: "card_clubs_02.png"
        anchors.centerIn: parent  // 将图片居中显示
        fillMode: Image.PreserveAspectFit  // 保持图片的宽高比
    }
}
