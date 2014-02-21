HEADERS+= ../../../src/modules/servo.hpp
HEADERS+= ../../../src/modules/modules.hpp
HEADERS+= ../../../src/coordinator/coordinator.hpp
HEADERS+= ../../../src/physical_calculator/physical_calculator.hpp
HEADERS+= ../../../src/physical_calculator/wheel.hpp
HEADERS+= ../../../src/physical_calculator/robot.hpp
HEADERS+= ~/Qt/5.2.0/gcc_64/include


CONFIG += debug


LIBS +=  -L/usr/local/lib -lBulletDynamics -lBulletCollision -lLinearMath

SOURCES+= ../../../src/physical_calculator/wheel.cpp
SOURCES+= ../../../src/physical_calculator/robot.cpp
SOURCES+= ../../../src/modules/modules.cpp
SOURCES+= ../../../src/physical_calculator/physical_calculator.cpp
SOURCES+= ../../../src/modules/servo.cpp
SOURCES+= ../../../src/coordinator/coordinator.cpp
SOURCES += main.cpp

INCLUDEPATH += /home/hugo/Qt/5.2.0/gcc_64/include
INCLUDEPATH +=  ../../../../aversive--/include/sasiae
INCLUDEPATH += /usr/local/include/bullet
 

TARGET = testcoordinator
