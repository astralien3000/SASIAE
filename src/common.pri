#Includes common configuration for all subdirectory .pro files.
INCLUDEPATH += . \
/usr/local/include/bullet \
/usr/include/bullet

WARNINGS += -Wall
QMAKE_CXXFLAGS = -std=c++11
LIBS += -L/usr/local/lib  
LIBS += -lLinearMath -lBulletDynamics -lBulletCollision

# The following keeps the generated files at least somewhat separate 
# from the source files.
UI_DIR = uics
MOC_DIR = mocs
OBJECTS_DIR = objs
