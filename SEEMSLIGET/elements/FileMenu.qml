import QtQuick 2.12

Row {
  anchors.centerIn: parent
  spacing: parent.width/6

  Button
  {
   id: loadButton
   buttonColor: "lightgrey"
   label: "Load"
  }

  Button
  {
   buttonColor: "grey"
   id: saveButton
   label: "Save"
  }

  Button
  {
   id: exitButton
   label: "Exit"
   buttonColor: "darkgrey"

   onButtonClick: Qt.quit()
  }
 }
