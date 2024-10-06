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

#CONFIG += android


SOURCES += \
        src/main.cpp \
        src/rule/Card.cpp \
        src/rule/Player.cpp \
        src/rule/PlayerModel.cpp \
        src/rule/Poker.cpp \
        src/rule/PublicCardModel.cpp \
        src/rule/testmodel.cpp \
        src/utility/Bizcommand.cpp \
        src/utility/Test.cpp \
        src/utility/Utility.cpp

RESOURCES += \
        assets/qml/qml.qrc \
        assets/images/images.qrc


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

HEADERS += \
    src/rule/Card.h \
    src/rule/Definitions.h \
    src/rule/Player.h \
    src/rule/PlayerModel.h \
    src/rule/Poker.h \
    src/rule/PublicCardModel.h \
    src/rule/testmodel.h \
    src/utility/Bizcommand.h \
    src/utility/Logger.h \
    src/utility/Test.h \
    src/utility/Utility.h
