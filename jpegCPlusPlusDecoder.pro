TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    jpeg_container.cpp \
    jpeg_interface.c

HEADERS += \
    jpeg_container.h \
    jpeg_interface.h

LIBS += -ljpeg

CONFIG += c++11

