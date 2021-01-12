function drawBackground(ctx) {
    ctx.save();
    ctx.fillStyle = "#ffffff";
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    ctx.strokeStyle = "#d7d7d7";
    ctx.beginPath();
    // Horizontal grid lines
    for (var i = 0; i < 12; i++) {
        ctx.moveTo(0, canvas.yGridOffset + i * canvas.yGridStep);
        ctx.lineTo(canvas.width, canvas.yGridOffset + i * canvas.yGridStep);
    }

    // Vertical grid lines
    var height = 35 * canvas.height / 36;
    var yOffset = canvas.height - height;
    var xOffset = 0;
    for (i = 0; i < chart.gridSize; i++) {
        ctx.moveTo(xOffset + i * chart.gridStep, yOffset);
        ctx.lineTo(xOffset + i * chart.gridStep, height);
    }
    ctx.stroke();

    // Right ticks
    ctx.strokeStyle = "#666666";
    ctx.beginPath();
    var xStart = canvas.width - tickMargin;
    ctx.moveTo(xStart, 0);
    ctx.lineTo(xStart, canvas.height);
    for (i = 0; i < 12; i++) {
        ctx.moveTo(xStart, canvas.yGridOffset + i * canvas.yGridStep);
        ctx.lineTo(canvas.width, canvas.yGridOffset + i * canvas.yGridStep);
    }
    ctx.moveTo(0, canvas.yGridOffset + 9 * canvas.yGridStep);
    ctx.lineTo(canvas.width, canvas.yGridOffset + 9 * canvas.yGridStep);
    ctx.closePath();
    ctx.stroke();

    ctx.restore();
}

function drawScales(ctx, high, low, vol)
{
    ctx.save();
    ctx.strokeStyle = "#888888";
    ctx.font = "10px Open Sans"

    ctx.beginPath();

    // prices on y-axis
    var x = canvas.width - tickMargin + 3;
    var priceStep = (high - low) / 9.0;
    for (var i = 0; i < 10; i += 2) {
        var price = parseFloat(high - i * priceStep).toFixed(1);
        ctx.text(price, x, canvas.yGridOffset + i * yGridStep - 2);
    }

    // volume scale
    for (i = 0; i < 3; i++) {
        var volume = volumeToString(vol - (i * (vol/3)));
        ctx.text(volume, x, canvas.yGridOffset + (i + 9) * yGridStep + 10);
    }

    ctx.closePath();
    ctx.stroke();
    ctx.restore();
}

function drawPrice(ctx, from, to, color, price, points, highest, lowest)
{
    ctx.save();
    ctx.globalAlpha = 0.7;
    ctx.strokeStyle = color;

    ctx.lineWidth = numPoints > 200 ? 1 : 3

    ctx.beginPath();

    var end = points.length;

    var range = highest - lowest;
    if (range == 0) {
        range = 1;
    }

    for (var i = 0; i < end; i += pixelSkip) {
        var x = points[i].x;
        var y = points[i][price];
        var h = 9 * yGridStep;

        y = h * (lowest - y)/range + h + yGridOffset;

        if (i == 0) {
            ctx.moveTo(x, y);
        } else {
            ctx.lineTo(x, y);
        }
    }
    ctx.stroke();
    ctx.restore();
}

function drawVolume(ctx, from, to, color, price, points, highest)
{
    ctx.save();
    ctx.fillStyle = color;
    ctx.globalAlpha = 0.8;
    ctx.lineWidth = 0;
    ctx.beginPath();

    var end = points.length;
    var margin = 0;

    if (chart.activeChart === "month" || chart.activeChart === "week") {
        margin = 8;
        ctx.shadowOffsetX = 4;
        ctx.shadowBlur = 3.5;
        ctx.shadowColor = Qt.darker(color);
    }

    // To match the volume graph with price grid, skip drawing the initial
    // volume of the first day on chart.
    for (var i = 1; i < end; i += pixelSkip) {
        var x = points[i - 1].x;
        var y = points[i][price];
        y = canvas.height * (y / highest);
        y = 3 * y / 12;
        ctx.fillRect(x, canvas.height - y + yGridOffset,
                     canvas.xGridStep - margin, y);
    }

    ctx.stroke();
    ctx.restore();
}

function drawError(ctx, msg)
{
    ctx.save();
    ctx.strokeStyle = "#888888";
    ctx.font = "24px Open Sans"
    ctx.textAlign = "center"
    ctx.shadowOffsetX = 4;
    ctx.shadowOffsetY = 4;
    ctx.shadowBlur = 1.5;
    ctx.shadowColor = "#aaaaaa";
    ctx.beginPath();

    ctx.fillText(msg, (canvas.width - tickMargin) / 2,
                 (canvas.height - yGridOffset - yGridStep) / 2);

    ctx.closePath();
    ctx.stroke();
    ctx.restore();
}
