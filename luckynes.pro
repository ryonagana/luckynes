TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/luckynes.c \
    src/nes_types.c \
    src/cartridge.c

INCLUDEPATH += include

include(deployment.pri)


HEADERS += \
    include/nes_types.h \
    include/cartridge.h

