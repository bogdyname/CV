QT += quick

CONFIG += c++11

HEADERS += \
    include/stocklist.h \

SOURCES += \
    smv.cpp \
    src/stocklist.cpp \

DISTFILES += \
    scripts/draw.js

RESOURCES += qml.qrc
OTHER_FILES += *.qml content/*.qml content/images/*.png

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
