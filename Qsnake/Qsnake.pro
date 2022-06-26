QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    choosenewgame.cpp \
    endlessmode.cpp \
    main.cpp \
    mainwindow.cpp \
    pause.cpp \
    readfile.cpp \
    rules.cpp \
    snake.cpp

HEADERS += \
    ../../AppData/Local/Temp/QtCreator-qNinqE/clang-uiheader-svwyQf/ui_choosenewgame.h \
    ../../AppData/Local/Temp/QtCreator-qNinqE/clang-uiheader-svwyQf/ui_endlessmode.h \
    ../../AppData/Local/Temp/QtCreator-qNinqE/clang-uiheader-svwyQf/ui_mainwindow.h \
    ../../AppData/Local/Temp/QtCreator-qNinqE/clang-uiheader-svwyQf/ui_mainwindow.h \
    ../../AppData/Local/Temp/QtCreator-qNinqE/clang-uiheader-svwyQf/ui_rules.h \
    board.h \
    choosenewgame.h \
    endlessmode.h \
    mainwindow.h \
    pause.h \
    readfile.h \
    rules.h \
    snake.h

FORMS += \
    choosenewgame.ui \
    endlessmode.ui \
    mainwindow.ui \
    pause.ui \
    readfile.ui \
    rules.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
