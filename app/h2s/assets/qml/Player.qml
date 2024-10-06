import QtQuick 2.0

Item {
    id:player
    property var info
    property string uuid: info.uuid

    property string tagPlay: info.tagPlay
    property string tagDescribe: info.tagDescribe
    property string name: info.name
    property string rname: info.rname

    property int index: info.index
    property int chip: info.chip
    property var buyin: info.buyin

    property string position: info.position
    property var hand: info.hand

    width: 45
    height: width

//    Text {
//        anchors.centerIn: iTopCenter
//        text: player.name
//    }
//    Rectangle {
////            id: rectMain
//        anchors.centerIn: iCenter
//        width: 45
//        height: width
//        radius: width/2
//        color: "white"
//        border.color: "black"

//    }

    Grid {
        anchors.centerIn: parent
        columns: 3
        Item {id: iTopLeft;width: 45;height: 45;}
        Item {id: iTopCenter;width: 45; height: 45;
            Text {
                anchors.centerIn: parent
                text: player.name
            }
        }
        Item {id: iTopRight; width: 45;height: 45;}

        Item {id: iCenterLeft;width: 45;height: 45;}
        Item {id: iCenter;width: 45; height: 45;
            Rectangle {
        //            id: rectMain
                anchors.centerIn: parent
                width: 45
                height: width
                radius: width/2
                color: "white"
                border.color: "black"

            }
        }
        Item {id: iCenterRight;width: 45;height: 45;}

        Item {id: iBottomLeft; width: 45;height: 45}
        Item {id: iBottomCenter;width: 45;height: 45;}
        Item {id: iBottomRight;width: 45;height: 45;}



    }
}
