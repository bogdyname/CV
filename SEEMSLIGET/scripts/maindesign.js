function maxsize(xx, yy) {
    return xx > yy ? xx : yy;
}

function ensureVisible(r) {
    if (contentX >= r.x)
        contentX = r.x;
    else if (contentX + width <= r.x + r.width)
        contentX = r.x + r.width - width;
    if (contentY >= r.y)
        contentY = r.y;
    else if (contentY + height <= r.y + r.height)
        contentY = r.y + r.height - height;
}

function tts() {
    return;
}
