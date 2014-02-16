TARGET= moteur

QMAKE_CXXFLAGS = -std=c++0x -Wall -Wextra

LIBS += -L/usr/local/lib -L/home/hugo/Qt/5.2.0/gcc_64/lib -lBulletDynamics -lBulletCollision -lLinearMath 


INCLUDEPATH= /usr/local/include/bullet \
/usr/include/bullet \
/home/hugo/Qt/5.2.0/gcc_64/include \
../../../aversive--/include/sasiae


HEADERS = /usr/local/include/bullet/btBulletDynamicsCommon.h \
physical_calculator.hpp \
robot.hpp \
wheel.hpp 


SOURCES = physical_calculator.cpp \
main.cpp \
robot.cpp \
wheel.cpp 
