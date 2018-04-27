import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id: root

    property int fieldWidth: root.width / app.nPlayFields

    visible: true
    width: 640
    height: 480

    Row {
        Repeater {
            model: app.playFields

            Rectangle {
                color: modelData.color
                width: root.fieldWidth
                height: root.height

                MultiPointTouchArea {
                    anchors.fill: parent

                    onPressed: {
                        if(touchPoints.length === 1) {
                            modelData.onPressed()
                        }
                    }

                    onCanceled: {
                        if(touchPoints.length === 1) {
                            modelData.onReleased()
                        }
                    }

                    onReleased: {
                        if(touchPoints.length === 1) {
                            modelData.onReleased()
                        }
                    }

                    onGestureStarted: {
                        gesture.grab();
                    }
                }
            }
        }
    }
}

