import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Window 2.14

Page {
//    width: 120
//    height: 120
//    width: Screen.width
//    height: Screen.height
    anchors.fill: parent

    title: qsTr("Page 1")

    Rectangle {
        anchors.fill: parent
        color: "red"
    }

    Rectangle {
        id: rect
        anchors.centerIn: parent
        width: parent.width - 10
        height: parent.height - 10
        color: "green"
    }

    Label {
        text: qsTr("You are on Page 1.")
        anchors.centerIn: parent
    }

    Button {
        anchors.centerIn: parent
        id: btnClick
        onClicked: {
            rect.width -= 10
            rect.height -= 10

            if(rect.width < 20)
            {
                rect.width = parent.width
                rect.height = parent.height
            }
        }
    }


}
