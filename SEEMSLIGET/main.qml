import QtQuick 2.12
import QtQuick.Window 2.12
import "autotest.js" as MainTest
import "maindesign.js" as MainScripts

Window
{
    visible: true
    width: 640
    height: 480
    title: qsTr("LOVE")

    MouseArea
    {
        anchors.bottomMargin: 330
        anchors.leftMargin: 0
        anchors.fill: parent
        onClicked:
        {
            console.log(qsTr('Clicked on background. Text: "'
                             + textEdit.text + '"'))
        }
    }

    TextEdit
    {
        id: textEdit
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20

        Rectangle
        {
            width: MainScripts.maxsize(parent.width, parent.height)
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }
}
