! include( ../common.pri ) {
      error( "Couldn't find the common.pri file!" )
}

CONFIG += plugin 
TEMPLATE = lib
TARGET = MotorWheel
DESTDIR = ../../build/
QT += widgets core
QMAKE_CXXFLAGS = -std=c++11

HEADERS += ../physical_calculator/wheel.hpp \
           ../physical_calculator/robot.hpp
HEADERS += ../common/object_config.hpp \
           ../common/position_data.hpp \
           module.hpp \
           factory.hpp

HEADERS += motor_wheel.hpp \
           motor_wheel_factory.hpp

SOURCES += ../physical_calculator/wheel.cpp \
           ../physical_calculator/robot.cpp
SOURCES += ../common/object_config.cpp \
           ../common/position_data.cpp \
          factory.cpp

SOURCES += motor_wheel.cpp \
           motor_wheel_factory.cpp

OTHER_FILES += motor_wheel_factory.json
