import QtQuick 2.6
import QtQuick.Window 2.2

import "lib/misulib/qml/playfield"

Window {
    property int buttonRadius: 0
    property int borderWidth: 0
    property color borderColor: "#333333"
    property color fgColor: "#CCCCCC"
    property color bgColor: "#CCCCCC"

    id: root

    visible: true
    width: 640
    height: 480
    color: bgColor

    PlayArea {
        id: playAreaRow
        visible: true
        controller: app.playArea
        anchors.fill: parent
    }

    Bubbles {
        anchors.fill: parent
        model: app.touchHistory.events
    }
}

