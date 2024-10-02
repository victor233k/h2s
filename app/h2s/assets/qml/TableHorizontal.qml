import QtQuick 2.14
import QtQuick.Controls 2.14

//横桌
Page {

    Item  {
        id: betItem
        anchors.centerIn: parent
        width: tableRect.width * 0.88
        height: tableRect.height * 0.8
//        color: "transparent"
//        border.color: "black"
//        radius: height / 2
    }


    Rectangle {
        id:tableRect
        anchors.centerIn: parent
        width: parent.width * 0.8
        height: parent.height * 0.8
        radius: height / 2
        color: "#87CEFA"

        Column {
            anchors.centerIn: parent
            spacing: 20
            Row {
                spacing: 1
                Card {

                }
                Card {

                }
                Card {

                }
                Card {

                }
                Card {

                }
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    text: "pot : "
                }
                Text {
                    text: "18"
                }
            }
        }

    }



    PathView {
        model: 10 // 假设我们要在路径上放置10个控件
        path: playerPath
        delegate: Player {

        }

        Path {
            id: playerPath

            startX: tableRect.x + tableRect.width / 2
            startY: tableRect.y + tableRect.height
            PathLine {
                x: tableRect.x + tableRect.height / 2
                y: tableRect.y + tableRect.height
            }

            PathArc {
                x: tableRect.x + tableRect.height / 2
                y: tableRect.y
                radiusX: tableRect.height / 2
                radiusY: tableRect.height / 2
            }

            PathLine {
                x: tableRect.x + tableRect.width - tableRect.height / 2
                y: tableRect.y
            }

            PathArc {

                x: tableRect.x + tableRect.width - tableRect.height / 2
                y: tableRect.y + tableRect.height
                radiusX: tableRect.height / 2
                radiusY: tableRect.height / 2
            }

            PathLine {
                x: tableRect.x + tableRect.width / 2
                y: tableRect.y + tableRect.height
            }
        }
    }
    PathView {
        model: 10 // 假设我们要在路径上放置10个控件
        path: betPath
        delegate: Rectangle {
            width: 30
            height: 10
            color: "green"
        }
        Path {
            id: betPath

            startX: betItem.x + betItem.width / 2
            startY: betItem.y + betItem.height
            PathLine {
                x: betItem.x + betItem.height / 2
                y: betItem.y + betItem.height
            }

            PathArc {
                x: betItem.x + betItem.height / 2
                y: betItem.y
                radiusX: betItem.height / 2
                radiusY: betItem.height / 2
            }

            PathLine {
                x: betItem.x + betItem.width - betItem.height / 2
                y: betItem.y
            }

            PathArc {

                x: betItem.x + betItem.width - betItem.height / 2
                y: betItem.y + betItem.height
                radiusX: betItem.height / 2
                radiusY: betItem.height / 2
            }

            PathLine {
                x: betItem.x + betItem.width / 2
                y: betItem.y + betItem.height
            }
        }
    }

}
