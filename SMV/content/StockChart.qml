import QtQuick 2.15
import QtQuick.Layouts 1.1
import "."

Rectangle {
    id: chart

    property var stockModel: null
    property var startDate: new Date()
    property var endDate: new Date()
    property string activeChart: "week"
    property var settings
    property int gridSize: 4
    property real gridStep: gridSize ? (canvas.width - canvas.tickMargin) / gridSize : canvas.xGridStep

    function update() {
        endDate = new Date(stockModel.newest);
        if (chart.activeChart === "month") {
            chart.startDate = new Date(stockModel.newest.getFullYear(),
                                       stockModel.newest.getMonth() - 1,
                                       stockModel.newest.getDate());
            gridSize = 4;
        }
        else if (chart.activeChart === "quarter") {
            chart.startDate = new Date(stockModel.newest.getFullYear(),
                                       stockModel.newest.getMonth() - 3,
                                       stockModel.newest.getDate());
            gridSize = 3;
        }
        else if (chart.activeChart === "halfyear") {
            chart.startDate = new Date(stockModel.newest.getFullYear(),
                                       stockModel.newest.getMonth() - 6,
                                       stockModel.newest.getDate());
            gridSize = 6;
        }
        else {
            chart.startDate = new Date(stockModel.newest.getFullYear(),
                                       stockModel.newest.getMonth(),
                                       stockModel.newest.getDate() - 7);
            gridSize = 0;
        }

        canvas.requestPaint();
    }

    // Returns a shortened, readable version of the potentially
    // large volume number.
    function volumeToString(value) {
        if (value < 1000)
            return value;
        var exponent = parseInt(Math.log(value) / Math.log(1000));
        var shortVal = parseFloat(parseFloat(value) / Math.pow(1000, exponent)).toFixed(1);

        // Drop the decimal point on 3-digit values to make it fit
        if (shortVal >= 100.0) {
            shortVal = parseFloat(shortVal).toFixed(0);
        }
        return shortVal + "KMBTG".charAt(exponent - 1);
    }

    GridLayout {
        anchors.fill: parent
        columns: 6
        rows: 3
        columnSpacing: 4

        Button {
            id: weekButton
            text: "Week"
            buttonEnabled: chart.activeChart === "week"
            onClicked: {
                chart.activeChart = "week";
                chart.update();
            }
        }

        Button {
            id: monthButton
            text: "Month"
            buttonEnabled: chart.activeChart === "month"
            onClicked: {
                chart.activeChart = "month";
                chart.update();
            }
        }

        Button {
            id: quarterlyButton
            text: "3 Months"
            buttonEnabled: chart.activeChart === "quarter"
            onClicked: {
                chart.activeChart = "quarter";
                chart.update();
            }
        }

        Button {
            id: halfYearlyButton
            text: "6 Months"
            buttonEnabled: chart.activeChart === "halfyear"
            onClicked: {
                chart.activeChart = "halfyear";
                chart.update();
            }
        }

        Canvas {
            id: canvas
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.columnSpan: 6
            // Uncomment below lines to use OpenGL hardware accelerated rendering.
            // See Canvas documentation for available options.
            // renderTarget: Canvas.FramebufferObject
            // renderStrategy: Canvas.Threaded

            property int pixelSkip: 1
            property int numPoints: 1
            property int tickMargin: 34

            property real xGridStep: (canvas.width - tickMargin) / numPoints
            property real yGridOffset: canvas.height / 26
            property real yGridStep: canvas.height / 12

            onPaint: {
                numPoints = stockModel.indexOf(chart.startDate);
                if (chart.gridSize == 0)
                    chart.gridSize = numPoints

                var ctx = canvas.getContext("2d");
                ctx.globalCompositeOperation = "source-over";
                ctx.lineWidth = 1;

                drawBackground(ctx);

                if (!stockModel.ready) {
                    drawError(ctx, "No data available.");
                    return;
                }

                var highestPrice = 0;
                var highestVolume = 0;
                var lowestPrice = -1;
                var points = [];
                for (var i = numPoints, j = 0; i >= 0 ; i -= pixelSkip, j += pixelSkip) {
                    var price = stockModel.get(i);
                    if (parseFloat(highestPrice) < parseFloat(price.high))
                        highestPrice = price.high;
                    if (parseInt(highestVolume, 10) < parseInt(price.volume, 10))
                        highestVolume = price.volume;
                    if (lowestPrice < 0 || parseFloat(lowestPrice) > parseFloat(price.low))
                        lowestPrice = price.low;
                    points.push({
                                    x: j * xGridStep,
                                    open: price.open,
                                    close: price.close,
                                    high: price.high,
                                    low: price.low,
                                    volume: price.volume
                                });
                }

                if (settings.drawHighPrice)
                    drawPrice(ctx, 0, numPoints, settings.highColor, "high", points, highestPrice, lowestPrice);
                if (settings.drawLowPrice)
                    drawPrice(ctx, 0, numPoints, settings.lowColor, "low", points, highestPrice, lowestPrice);
                if (settings.drawOpenPrice)
                    drawPrice(ctx, 0, numPoints,settings.openColor, "open", points, highestPrice, lowestPrice);
                if (settings.drawClosePrice)
                    drawPrice(ctx, 0, numPoints, settings.closeColor, "close", points, highestPrice, lowestPrice);

                drawVolume(ctx, 0, numPoints, settings.volumeColor, "volume", points, highestVolume);
                drawScales(ctx, highestPrice, lowestPrice, highestVolume);
            }
        }

        Text {
            id: fromDate
            color: "#000000"
            font.family: Settings.fontFamily
            font.pointSize: 8
            Layout.alignment: Qt.AlignLeft
            text: "| " + startDate.toDateString()
        }

        Text {
            id: toDate
            color: "#000000"
            font.family: Settings.fontFamily
            font.pointSize: 8
            Layout.alignment: Qt.AlignRight
            Layout.rightMargin: canvas.tickMargin
            Layout.columnSpan: 5
            text: endDate.toDateString() + " |"
        }
    }
}
