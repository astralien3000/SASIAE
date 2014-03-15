######################################################################
# Automatically generated by qmake (3.0) dim. f�vr. 16 11:48:39 2014
######################################################################

TEMPLATE = app
TARGET = gui
INCLUDEPATH += . \
/usr/include/bullet \
/usr/include/bullet/Glut/GL \
../../../aversive--/include/sasiae \
/usr/local/include/bullet

QT += widgets
QMAKE_CXXFLAGS = -std=c++11
LIBS += -lBulletDynamics -lBulletCollision -lLinearMath -lglut -lGLU

# Input
HEADERS += mainwindow.h ui_mainwindow.h \
    table.h \
    item_robot.h 

HEADERS += ../coordinator/coordinator.hpp \
    ../coordinator/physical_coordinator.hpp \
    ../coordinator/robot_coordinator.hpp \
    ../coordinator/module_coordinator.hpp \
    ../coordinator/schedule_coordinator.hpp \
    ../coordinator/base_coordinator.hpp \
    ../coordinator/gui_coordinator.hpp

HEADERS += ../physical_calculator/physical_calculator.hpp \
    ../physical_calculator/robot.hpp \
    ../physical_calculator/wheel.hpp \
    ../physical_calculator/printable_mobile_object.hpp \
    ../physical_calculator/position_data.hpp

HEADERS += ../modules/servo.hpp \
    ../modules/module.hpp \
    ../modules/encoder.hpp \
    ../modules/motor_wheel.hpp

FORMS += mainwindow.ui
SOURCES += main.cpp mainwindow.cpp \
    table.cpp \
    item_robot.cpp \

SOURCES += ../coordinator/coordinator.cpp \
    ../coordinator/physical_coordinator.cpp \
    ../coordinator/robot_coordinator.cpp \
    ../coordinator/module_coordinator.cpp \
    ../coordinator/schedule_coordinator.cpp \
    ../coordinator/gui_coordinator.cpp

SOURCES += ../physical_calculator/physical_calculator.cpp \
    ../physical_calculator/robot.cpp \
    ../physical_calculator/wheel.cpp \
    ../physical_calculator/printable_mobile_object.cpp \
    ../physical_calculator/position_data.cpp

SOURCES += ../modules/motor_wheel.cpp \
    ../modules/servo.cpp \
    ../modules/encoder.cpp

