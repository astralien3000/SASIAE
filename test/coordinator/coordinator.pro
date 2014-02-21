TEMPLATE = app
TARGET = test_coordinator
INCLUDEPATH += /usr/local/include/bullet \
/usr/include/bullet \
../../src/modules \
../../../aversive--/include/sasiae

QT += testlib
CONFIG += debug
LIBS += -lBulletDynamics -lBulletCollision -lLinearMath -L/usr/local/lib
# Input
HEADERS += modules.hpp \
physical_calculator.hpp \
../../src/coordinator/coordinator.hpp \
../../src/modules/servo.hpp \
../../src/physical_calculator/robot.hpp \
../../src/physical_calculator/wheel.hpp \
../../../aversive--/include/sasiae

SOURCES += test_coordinator.cpp \
modules.cpp \
physical_calculator.cpp \
../../src/physical_calculator/robot.cpp \
../../src/physical_calculator/wheel.cpp \
../../src/coordinator/coordinator.cpp \
../../src/modules/servo.cpp
