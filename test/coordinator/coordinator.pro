TEMPLATE = app
TARGET = test_coordinator
INCLUDEPATH += /usr/local/include/bullet \
/usr/include/bullet \
/usr/local/include/qt5 \
../../src/modules \
../../../aversive--/include/sasiae

QT += testlib
CONFIG += debug
QMAKE_CXXFLAGS = -std=c++11

LIBS += -lBulletDynamics -lBulletCollision -lLinearMath -L/usr/local/lib
# Input
HEADERS += modules.hpp \
physical_calculator.hpp \
../../src/coordinator/coordinator.hpp \
 ../../src/coordinator/physical_coordinator.hpp \
 ../../src/coordinator/robot_coordinator.hpp \
 ../../src/coordinator/module_coordinator.hpp \
 ../../src/coordinator/schedule_coordinator.hpp \
 ../../src/coordinator/base_coordinator.hpp \
../../src/modules/module.hpp \
../../src/modules/servo.hpp \
../../src/modules/encoder.hpp \
../../src/modules/motor_wheel.hpp \
../../src/physical_calculator/robot.hpp \
../../src/physical_calculator/wheel.hpp \
../../src/physical_calculator/printable_mobile_object.hpp \
../../../aversive--/include/sasiae

SOURCES += test_coordinator.cpp \
modules.cpp \
physical_calculator.cpp \
../../src/physical_calculator/robot.cpp \
../../src/physical_calculator/wheel.cpp \
../../src/physical_calculator/printable_mobile_object.cpp \
../../src/coordinator/coordinator.cpp \
 ../../src/coordinator/physical_coordinator.cpp \
 ../../src/coordinator/robot_coordinator.cpp \
 ../../src/coordinator/module_coordinator.cpp \
 ../../src/coordinator/schedule_coordinator.cpp \
../../src/modules/encoder.cpp \
../../src/modules/motor_wheel.cpp \
../../src/modules/servo.cpp

