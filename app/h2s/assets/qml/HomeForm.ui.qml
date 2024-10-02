import QtQuick 2.14
import QtQuick.Controls 2.14

Page {

    title: qsTr("Home")

    Column {
        anchors.centerIn: parent
        Label {
            text: qsTr("You are on the home page log.")

        }
        Label {
            text: qsTr(bizCommand.logTest)
        }
    }
}
