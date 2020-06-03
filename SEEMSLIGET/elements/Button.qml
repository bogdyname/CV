import QtQuick 2.12

Rectangle
{
    id: button

    width: 100
    height: 40

    Text
    {
        id: labelOfButton
        text: "open file"
        anchors.centerIn: parent;
    }

    property color buttonColor: "lightblue"
    property color onHoverColor: "gold"
    property color borderColor: "white"

    signal buttonClick()
    onButtonClick:
    {
       console.log(buttonLabel.text + " clicked" )
    }

    MouseArea
    {
        onClicked: buttonClick()
        hoverEnabled: true
        onEntered: parent.border.color = onHoverColor
        onExited: parent.border.color = borderColor
    }

    color: buttonMouseArea.pressed ? Qt.darker(buttonColor, 1.5) : buttonColor
}
