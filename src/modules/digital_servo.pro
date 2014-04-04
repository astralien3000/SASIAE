! include( ../common.pri ) {
      error( "Couldn't find the common.pri file!" )
}

CONFIG += plugin 
TEMPLATE = lib
TARGET = DigitalServo
DESTDIR = ../../build/
QT += widgets core
QMAKE_CXXFLAGS = -std=c++11

HEADERS += ../physical_calculator/mesh.hpp \
           ../physical_calculator/dist_sensor.hpp \
           ../physical_calculator/world.hpp \
           ../physical_calculator/position_data_bullet.hpp \
           ../physical_calculator/robot.hpp
HEADERS += ../common/object_config.hpp \
           ../common/position_data.hpp \
           module.hpp \
           factory.hpp
HEADERS += digital_servo.hpp \
           digital_servo_factory.hpp

SOURCES += ../physical_calculator/mesh.cpp \
           ../physical_calculator/dist_sensor.cpp \
           ../physical_calculator/world.cpp \
           ../physical_calculator/position_data_bullet.cpp \
           ../physical_calculator/robot.cpp
SOURCES += ../common/object_config.cpp \
           ../common/position_data.cpp \
           factory.cpp
SOURCES += digital_servo.cpp \
           digital_servo_factory.cpp


OTHER_FILES += digital_servo_factory.json
