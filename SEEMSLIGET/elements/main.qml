import QtQuick 2.12
import QtQuick.Window 2.1
import "../scripts/autotest.js" as MainTest
import "../scripts/maindesign.js" as MainScripts
//import "texteditor.qml" as SpaceEdit

Window
{
    id: mainwindow
    visible: true
    width: 640
    height: 480
    title: qsTr("LOVE")

    TextEditor
    {

    }
}
