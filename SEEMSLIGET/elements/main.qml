import QtQuick 2.12
import QtQuick.Window 2.1
import "../scripts/main.js" as MainScripts

Window
{
    id: mainwindow
    visible: true
    width: 640
    height: 480
    title: qsTr("LOVE")

    Rectangle
    {
        id: button
        color: "grey"
        width: 100
        height: 40

        Text
        {
            id: labelOfButton
            text: "tts"
            anchors.centerIn: parent;
        }

        MouseArea
        {
         id: buttonMouseArea
         anchors.fill: parent

         onClicked: console.log(labelOfButton.text + "'clicked'")
         }
    }

    TextEditor
    {

    }
}
