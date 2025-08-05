#QT -= gui
QT += core gui

CONFIG += c++20 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    view/gui/app_gui.cpp \
    view/gui/board_gui.cpp \
    view/gui/reception.cpp \
    view/gui/option.cpp \
    view/console/view.cpp \
    model/board.cpp \
    model/box.cpp \
    model/command_manager.cpp \
    model/direction.cpp \
    model/element.cpp \
    model/game.cpp \
    model/level.cpp \
    model/move_command.cpp \
    model/position.cpp \
    model/rule.cpp \
    controller/controller.cpp \
    test/test.cpp \
    main.cpp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    view/gui/app_gui.h \
    view/gui/board_gui.h \
    view/gui/option.h \
    view/gui/reception.h \
    view/console/view.h \
    model/board.h \
    model/box.h \
    model/command_manager.h \
    model/direction.h \
    model/element.h \
    model/game.h \
    model/level.h \
    model/move_command.h \
    model/position.h \
    model/rule.h \
    controller/controller.h \
    test/test.h \
    observer/observer.h \
    observer/observable.h



