QT += quick

CONFIG += c++11
CONFIG += c++17

HEADERS += \
    cryptoalgo.h \
    filemanager.h

SOURCES += \
        cryptoalgo.cpp \
        filemanager.cpp \
        main.cpp

RESOURCES += qml.qrc

QML_IMPORT_PATH =

QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
