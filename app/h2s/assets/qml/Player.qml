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

    width: 20
    height: width
    Rectangle {
        width: parent.width
        height: width
        radius: width/2
        color: "red"
    }
}
