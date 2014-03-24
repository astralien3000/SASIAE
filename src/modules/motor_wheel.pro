! include( ../common.pri ) {
      error( "Couldn't find the common.pri file!" )
}

CONFIG += plugin 
TEMPLATE = lib
TARGET = MotorWheel
DESTDIR = ../../build/
QT += widgets core
QMAKE_CXXFLAGS = -std=c++11

HEADERS = module.hpp motor_wheel.hpp ../common/object_config.hpp ../common/position_data.hpp ../physical_calculator/wheel.hpp ../physical_calculator/robot.hpp
SOURCES = motor_wheel.cpp ../common/object_config.cpp ../common/position_data.cpp ../physical_calculator/wheel.cpp ../physical_calculator/robot.cpp
OTHER_FILES += motor_wheel.json
