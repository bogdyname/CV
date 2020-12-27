import QtQuick 2.15
import QtQml.Models 2.1
import QtQuick.Layouts 1.1
import "content"

Rectangle {
    id: mainRect
    width: 1000
    height: 700

    property alias currentIndex: root.currentIndex

    ColumnLayout {
        anchors.fill: parent

        Banner {
            id: banner
            Layout.fillWidth: true
        }

        ListView {
            id: root
            Layout.fillHeight: true
            Layout.fillWidth: true
            snapMode: ListView.SnapOneItem
            highlightRangeMode: ListView.StrictlyEnforceRange
            highlightMoveDuration: 250
            focus: false
            orientation: ListView.Horizontal
            boundsBehavior: Flickable.StopAtBounds

            StockModel {
                id: stock
                stockId: listView.currentStockId
                stockName: listView.currentStockName
                onStockIdChanged: stock.updateStock();
                onDataReady: {
                    root.currentIndex = 1
                    stockView.update()
                }
            }

            model: ObjectModel {
                StockListView {
                    id: listView
                    width: root.width
                    height: root.height
                }

                StockView {
                    id: stockView
                    width: root.width
                    height: root.height
                    stocklist: listView
                    stock: stock
                }
            }
        }
    }
}
