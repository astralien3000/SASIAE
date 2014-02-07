HEADERS+= ../../../src/modules/servo.hpp
HEADERS+= ../../../src/modules/modules.hpp
HEADERS+= ../../../src/coordinator/coordinator.hpp
HEADERS+= ../../../src/physical_calculator/physical_calculator.hpp


CONFIG += debug


LIBS +=  -L/usr/local/lib -lBulletDynamics -lBulletCollision -lLinearMath

SOURCES+= ../../../src/modules/modules.cpp
SOURCES+= ../../../src/physical_calculator/physical_calculator.cpp
SOURCES+= ../../../src/modules/servo.cpp
SOURCES+= ../../../src/coordinator/coordinator.cpp
SOURCES += main.cpp

INCLUDEPATH += /usr/local/include/bullet
INCLUDEPATH +=  ../../../../aversive--/include/sasiae
INCLUDEPATH += /usr/local/include/bullet
 

TARGET = testcoordinator
