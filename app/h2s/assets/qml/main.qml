import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Window 2.14

ApplicationWindow {
//Window {
    id: window
    visible: true

    title: qsTr("Stack")

//    header: ToolBar {
    onClosing: {
        if(Qt.platform.os === "android")
        {
            close.accepted = false;
        }
        if(stackView.depth > 1)
        {
            stackView.pop()
        } else {
            bizCommand.appQuit(0)
        }
    }

    footer: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.58
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Page 1")
                width: parent.width
                onClicked: {
                    stackView.push("Page1Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Page 2")
                width: parent.width
                onClicked: {
                    stackView.push("Page2Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Page 3")
                width: parent.width
                onClicked: {
                    stackView.push("AllCards.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Card Pick")
                width: parent.width
                onClicked: {
                    stackView.push("CardPick.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("TableHorizontal")
                width: parent.width
                onClicked: {
                    stackView.push("TableHorizontal.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("TableVertical")
                width: parent.width
                onClicked: {
                    stackView.push("TableVertical.qml")
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "HomeForm.ui.qml"
        anchors.fill: parent
    }

}
