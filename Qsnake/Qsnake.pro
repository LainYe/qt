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
    pairmode.cpp \
    pause.cpp \
    qwaitingdialog.cpp \
    readfile.cpp \
    rules.cpp \
    singlemode.cpp \
    snake.cpp \
    test.cpp

HEADERS += \
    board.h \
    choosenewgame.h \
    endlessmode.h \
    mainwindow.h \
    pairmode.h \
    pause.h \
    qwaitingdialog.h \
    readfile.h \
    rules.h \
    singlemode.h \
    snake.h \
    test.h

FORMS += \
    choosenewgame.ui \
    endlessmode.ui \
    mainwindow.ui \
    pairmode.ui \
    pause.ui \
    readfile.ui \
    rules.ui \
    singlemode.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    maps.qrc
