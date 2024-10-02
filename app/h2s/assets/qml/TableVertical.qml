import QtQuick 2.14
import QtQuick.Controls 2.14


//竖桌
Page {
    anchors.fill: parent
    anchors.centerIn: parent


    Rectangle {
        id:tableRect
        anchors.centerIn: parent
        width: parent.width * 0.7
        height: parent.height * 0.7
        radius: width / 2
        color: "#87CEFA"

    }

    Column {
        anchors.centerIn: parent
        spacing: 20

        ListView {
            model: 5
            width: 30 * 5
            height: 60
            interactive: false
            orientation: ListView.Horizontal
            delegate: Card {

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


    PathView {

        x: tableRect.x
        y: tableRect.y

        model: 8 // 假设我们要在路径上放置10个控件
        path: playerPath
        delegate: Player {

        }

        Path {
            id: playerPath
            property int rWidth: tableRect.width
            property int rHeight: tableRect.height
            startX: rWidth / 2
            startY: rHeight
            PathArc {
                x:  0
                y:  tableRect.height - tableRect.width / 2
                radiusX: tableRect.width / 2
                radiusY: tableRect.width / 2
            }

            PathLine {
                x: 0
                y: tableRect.width / 2
            }

            PathArc {
                x: tableRect.width
                y: tableRect.width / 2
                radiusX: tableRect.width / 2
                radiusY: tableRect.width / 2
            }

            PathLine {
                x: tableRect.width
                y: tableRect.height - tableRect.width / 2
            }

            PathArc {
                x: tableRect.width / 2
                y: tableRect.height
                radiusX: tableRect.width / 2
                radiusY: tableRect.width / 2
            }

        }
    }

}
