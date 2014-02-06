TEMPLATE = app
TARGET = test_coordinator
INCLUDEPATH += /usr/local/include/bullet \
                /usr/include/bullet \
                ../../src/modules
QT += testlib
CONFIG += debug
LIBS += -lBulletDynamics -lBulletCollision -lLinearMath -L/usr/local/lib
# Input
HEADERS += modules.hpp \
	   physical_calculator.hpp \
     ../../src/coordinator/coordinator.hpp
SOURCES += test_coordinator.cpp \
           modules.cpp \
	   physical_calculator.cpp \
     ../../src/coordinator/coordinator.cpp
