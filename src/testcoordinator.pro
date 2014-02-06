HEADERS+= coordinator/modules/servo.hpp
HEADERS+= modules/modules.hpp
HEADERS+= coordinator/coordinator.hpp
HEADERS+= physical_calculator/physical_calculator.hpp
HEADERS+= ../../aversive--/include/sasiae/client_thread.hpp


LIBS +=  -L/usr/local/lib -lBulletDynamics -lBulletCollision -lLinearMath

SOURCES+= modules/modules.cpp
SOURCES+= modules/servo.cpp
SOURCES+= physical_calculator/physical_calculator.cpp
SOURCES+= coordinator/coordinator.cpp
SOURCES += main.cpp

INCLUDEPATH += /usr/local/include/bullet
INCLUDEPATH +=  ../../aversive--/include/sasiae
INCLUDEPATH += /usr/local/include/bullet
 

TARGET = testcoordinator
