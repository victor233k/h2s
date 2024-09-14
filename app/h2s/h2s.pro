QT += widgets quick qml gui

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

PRJDIR       = .
DESTDIR     = $$PRJDIR/bin

TARGET = h2s

HEADERS += \
    src/utility/Bizcommand.h \
    src/utility/Logger.h \
    src/utility/Utility.h \
    src/rule/PokerCard.h \
    src/rule/PokerCards.h \
    src/rule/Rule.h

SOURCES += \
        src/main.cpp \
        src/utility/Bizcommand.cpp \
        src/utility/Utility.cpp \
        src/rule/PokerCard.cpp \
        src/rule/PokerCards.cpp \
        src/rule/Rule.cpp

RESOURCES += \
        assets/qml/qml.qrc \
        assets/images/images.qrc \
        assets/fonts/fonts.qrc \


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


