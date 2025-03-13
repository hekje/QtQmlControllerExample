import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Controller-QML Example"

    signal buttonPressed // Define a signal

    // Text element to display the message
    Text {
        id: messageText
        text: controller.message  // Bind the text to the C++ message property
        anchors.centerIn: parent
        anchors.top: parent.top // Align the text to the bottom of the screen
        anchors.topMargin: 50 // Set some margin from the top
        font.pointSize: 20
        color: "blue"
    }

    // Button moved up
    Button {
        text: "Click Me"
        anchors.top: parent.top // Place the button at the top of the screen
        anchors.horizontalCenter: parent.horizontalCenter // Center horizontally
        anchors.topMargin: 20 // Add some margin from the top
        onClicked: buttonPressed() // Emit the custom signal
    }
}
