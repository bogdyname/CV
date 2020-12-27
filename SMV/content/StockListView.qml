import QtQuick 2.15
import "."

Rectangle {
    id: root
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    color: "white"

    property string currentStockId: ""
    property string currentStockName: ""

    ListView {
        id: view
        anchors.fill: parent
        clip: true
        keyNavigationWraps: true
        highlightMoveDuration: 0
        focus: true
        snapMode: ListView.SnapToItem
        model: StockListModel {}
        currentIndex: -1 // Don't pre-select any item

        onCurrentIndexChanged: {
            if (currentItem) {
                root.currentStockId = model.get(currentIndex).stockId;
                root.currentStockName = model.get(currentIndex).name;
            }
        }

        delegate: StockListDelegate {}

        highlight: Rectangle {
            width: view.width
            color: "#eeeeee"
        }
    }
}
