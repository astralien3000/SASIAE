! include( ../common.pri ) {
      error( "Couldn't find the common.pri file!" )
}

CONFIG += plugin 
TEMPLATE = lib
TARGET = Encoder
DESTDIR = ../../build/
QT += widgets core
QMAKE_CXXFLAGS = -std=c++11

HEADERS += ../physical_calculator/wheel.hpp \
           ../physical_calculator/robot.hpp
HEADERS += ../common/object_config.hpp \
           ../common/position_data.hpp \
           module.hpp \
           factory.hpp
HEADERS += encoder.hpp \
           encoder_factory.hpp

SOURCES += ../physical_calculator/wheel.cpp \
           ../physical_calculator/robot.cpp
SOURCES += ../common/object_config.cpp \
           ../common/position_data.cpp \
           factory.cpp

SOURCES += encoder.cpp \
           encoder_factory.cpp


OTHER_FILES += encoder_factory.json
