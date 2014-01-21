TEMPLATE = app
TARGET = test_modules
INCLUDEPATH += .
QT += testlib
CONFIG += debug

# Input
HEADERS += wheel.hpp \
           ../../src/modules/encoder.hpp \
           ../../src/modules/motor_wheel.hpp \
           ../../src/modules/modules.hpp
SOURCES += test_modules.cpp \
           wheel.cpp \
           ../../src/modules/encoder.cpp \
           ../../src/modules/motor_wheel.cpp \
           ../../src/modules/modules.cpp
