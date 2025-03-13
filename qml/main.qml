import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Controller-QML Example"

    signal buttonPressed // Define a signal

    Button {
        text: "Click Me"
        anchors.centerIn: parent

        onClicked: buttonPressed() // Emit the custom signal
    }
}

