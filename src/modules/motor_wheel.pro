CONFIG += plugin 
TEMPLATE = lib
TARGET = MotorWheel
INCLUDEPATH += . \
/usr/local/include/bullet \
/usr/include/bullet

QMAKE_CFLAGS = -Wno-unused-parameter
QMAKE_CFLAGS = -Wno-ignored-qualifiers
QMAKE_CFLAGS = -Wno-unused-variable
QT += widgets core
QMAKE_CXXFLAGS = -std=c++11
LIBS += -L/usr/local/lib -lBulletDynamics -L/usr/local/lib -lBulletCollision
LIBS += -lLinearMath

HEADERS = module.hpp motor_wheel.hpp ../common/object_config.hpp ../common/position_data.hpp ../physical_calculator/wheel.hpp ../physical_calculator/robot.hpp
SOURCES = motor_wheel.cpp ../common/object_config.cpp ../common/position_data.cpp ../physical_calculator/wheel.cpp ../physical_calculator/robot.cpp
OTHER_FILES += motor_wheel.json
