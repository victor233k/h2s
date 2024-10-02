import QtQuick 2.14
import QtQuick.Controls 2.14


Page {
    title: qsTr("Page 3")
//    anchors.fill: parent


    GridView {
        id: gridView
        anchors.fill: parent
        anchors.centerIn: parent
        anchors.margins: 5
        cellWidth: 59
        cellHeight: 120

        flow: GridView.FlowLeftToRight
//        model: 52
        model: images.length
        delegate: Item {
            width: gridView.cellWidth
            height: gridView.cellHeight

            Image {
                anchors.margins: 5
                anchors.fill: parent
                source: getImagePath(index)
                fillMode: Image.PreserveAspectFit
                asynchronous: true
            }
        }


    }

    function getImagePath(index) {

        // 检查索引是否在有效范围内
        if (index >= 0 && index < images.length) {
            return images[index];
        } else {
            console.warn("Index out of range: " + index);
            return "qrc:/c120/back.png"; // 返回一个默认图片路径
        }
    }

    property var images : [
        "qrc:/c120/back.png",
//        "qrc:/c120/C.png",
        "qrc:/c120/C2.png",
        "qrc:/c120/C3.png",
        "qrc:/c120/C4.png",
        "qrc:/c120/C5.png",
        "qrc:/c120/C6.png",
        "qrc:/c120/C7.png",
        "qrc:/c120/C8.png",
        "qrc:/c120/C9.png",
        "qrc:/c120/CT.png",
        "qrc:/c120/CJ.png",
        "qrc:/c120/CQ.png",
        "qrc:/c120/CK.png",
        "qrc:/c120/CA.png",
//        "qrc:/c120/D.png",
        "qrc:/c120/D2.png",
        "qrc:/c120/D3.png",
        "qrc:/c120/D4.png",
        "qrc:/c120/D5.png",
        "qrc:/c120/D6.png",
        "qrc:/c120/D7.png",
        "qrc:/c120/D8.png",
        "qrc:/c120/D9.png",
        "qrc:/c120/DT.png",
        "qrc:/c120/DJ.png",
        "qrc:/c120/DQ.png",
        "qrc:/c120/DK.png",
        "qrc:/c120/DA.png",
//        "qrc:/c120/H.png",
        "qrc:/c120/H2.png",
        "qrc:/c120/H3.png",
        "qrc:/c120/H4.png",
        "qrc:/c120/H5.png",
        "qrc:/c120/H6.png",
        "qrc:/c120/H7.png",
        "qrc:/c120/H8.png",
        "qrc:/c120/H9.png",
        "qrc:/c120/HT.png",
        "qrc:/c120/HJ.png",
        "qrc:/c120/HQ.png",
        "qrc:/c120/HK.png",
        "qrc:/c120/HA.png",
//        "qrc:/c120/S.png",
        "qrc:/c120/S2.png",
        "qrc:/c120/S3.png",
        "qrc:/c120/S4.png",
        "qrc:/c120/S5.png",
        "qrc:/c120/S6.png",
        "qrc:/c120/S7.png",
        "qrc:/c120/S8.png",
        "qrc:/c120/S9.png",
        "qrc:/c120/ST.png",
        "qrc:/c120/SJ.png",
        "qrc:/c120/SQ.png",
        "qrc:/c120/SK.png",
        "qrc:/c120/SA.png"
    ];
}
