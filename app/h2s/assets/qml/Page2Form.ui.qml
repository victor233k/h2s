import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Window 2.14

Page {
    id: page
    width: Screen.width / 2
    height: Screen.height - 100

    title: qsTr("Page 2")

    Rectangle {
        anchors.fill: parent
        color: "green"
    }

    Label {
        id: label
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }
}
