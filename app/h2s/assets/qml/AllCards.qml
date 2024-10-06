import QtQuick 2.14
import QtQuick.Controls 2.14

//Page {
Item {
//Popup {
    id: root
//    title: qsTr("all cards")

    property int caller: 0
    property real cellWidth: width * 0.0769
    property real cellHeight: cellWidth * 1.5
    property real gridViewWidth: cellWidth * 13
    property real gridViewHeight: cellHeight * 4

    signal okClicked(int cardId, int caller)
    signal backClicked(int caller)
    signal cancelClicked(int caller)
//    signal backClicked(int )

    Column {
//        anchors.centerIn: parent
        anchors.horizontalCenter: parent.horizontalCenter
        Item {
            anchors.horizontalCenter: parent.horizontalCenter
            width: root.gridViewWidth
            height: root.gridViewHeight
            GridView {
                id: gridView
                width: root.gridViewWidth
                height: root.gridViewHeight
                cellWidth: root.cellWidth
                cellHeight: root.cellHeight

                flow: GridView.FlowLeftToRight

                model: 52

                delegate: Item {
                    width: root.cellWidth
                    height: root.cellHeight

                    Button {
                        anchors.fill: parent
                        onClicked: {
                            gridView.currentIndex = index
                            root.okClicked(index, root.caller)
                        }
                    }

                    Image {
                        anchors.margins: 2
                        anchors.fill: parent
                        source: bizCommand.getCardImage(index)//TODO:考虑已被选择的情况？
                        fillMode: Image.PreserveAspectFit
                        asynchronous: true
                    }

//                    ShowBorder{
//                        id: bord
//        //                visible: false
//                        visible: gridView.currentIndex === index ? true : false
//                    }
                }
            }
        }


        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            Button {

                text: qsTr("关闭")
                onClicked: {
                    root.visible= false
                }
            }
            Button {

                text: qsTr("上一步")
                onClicked: {
                    root.backClicked(root.caller)
                }
            }
            Button {

                text: qsTr("取消")
                onClicked: {
                    root.cancelClicked(root.caller)
                }
            }
//            Button {
//                text: qsTr("确认")
//                onClicked: {
//                    root.okClicked(gridView.currentIndex, root.caller)
//                }
//            }
        }
    }

}
