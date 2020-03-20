QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/block/block_layout_item.cpp \
    src/blocks/blocks_controller.cpp \
    src/blocks/blocks_model.cpp \
    src/blocks/blocks_view.cpp \
    src/game.cpp \
    src/main.cpp \
    src/move_stack/move_stack_controller.cpp \
    src/move_stack/move_stack_view.cpp \
    #src/state_manager.cpp

HEADERS += \
    src/block/block.h \
    src/block/block_layout_item.h \
    src/block/free_block.h \
    src/block/numbered_block.h \
    src/blocks/blocks_controller.h \
    src/blocks/blocks_model.h \
    src/blocks/blocks_view.h \
    src/game.h \
    src/game_level.h \
    src/move_stack/move.h \
    src/move_stack/move_stack.h \
    src/move_stack/move_stack_controller.h \
    src/move_stack/move_stack_view.h \
    #src/state_manager.h

FORMS +=

TRANSLATIONS += \
    game-of-fifteen_pl_PL.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    LICENSE \
    README.md \
    src/game-of-fifteen_pl_PL.ts

STATECHARTS +=
