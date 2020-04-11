import QtQuick 2.12
import "../scripts/autotest.js" as MainTest
import "../scripts/maindesign.js" as MainScripts

Rectangle
{
    property alins TextEdit: textEditor.text
    property string name: "AreaForEdit"

    width: MainScripts.maxsize(parent.width, parent.height)

    border.width: 1
    radius: 1.5

    gradient: Gradient {
        GradientStop { position: 0.0; color: "blue" }
        GradientStop { position: 0.7; color: "gold" }
        GradientStop { position: 1.0; color: "silver" }
    }

    Flickable
    {
        id: flick

        width: 300; height: 200;
        contentWidth: edit.paintedWidth
        contentHeight: edit.paintedHeight
        clip: true

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

            onCursorRectangleChanged: MainScripts.ensureVisible(cursorRectangle)
        }
    }
}
