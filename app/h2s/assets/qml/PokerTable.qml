import QtQuick 2.0

Item {



    Rectangle {
        id:tableRect
        anchors.centerIn: parent
        width: parent.width * 0.8
        height: parent.height * 0.8
        radius: height / 2
        color: "#87CEFA"
//        color: "#000080"


        Row {
            anchors.centerIn: parent
            spacing: 10
            Item {
                width: 64
                height: 64
                Card {

                }
            }
            Item {
                width: 64
                height: 64
            }
            Item {
                width: 64
                height: 64
            }
        }



    }

    Image {
        id: myImage
        anchors.fill: parent

        source: bizCommand.appDir + "/PNG/Cards (large)/card_clubs_02.png"
        anchors.centerIn: parent  // 将图片居中显示
        fillMode: Image.PreserveAspectFit  // 保持图片的宽高比
    }
}
