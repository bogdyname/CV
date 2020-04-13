import QtQuick 2.12
import "../scripts/main.js" as MainScripts

Rectangle
{
    property alias text: textEditor.text
    property string name: "TextEditor"

    width: 100
    height: 100
    radius: 2
    smooth: true

    gradient: Gradient  {
            GradientStop  { position: 0.0; color: "darkGray" }
            GradientStop  { position: 0.5; color: "black" }
            GradientStop  { position: 1.0; color: "darkGray" }
    }

    TextEdit
    {
        id: textEditor
        color: "gray"
        width: flick.width
        height: flick.height
        focus: true
        wrapMode: TextEdit.Wrap
        x: 0
        y: 0
    }
}
