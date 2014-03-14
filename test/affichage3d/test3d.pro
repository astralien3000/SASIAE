TEMPLATE = app
TARGET = vue3d
DEPENDPATH += .
QT+=widgets
INCLUDEPATH += . /usr/include/bullet /usr/include/GL /usr/local/include/bullet /usr/local/lib ../../src/physical_calculator/  ../../../aversive--/include/sasiae /usr/include/qt5


QMAKE_CXXFLAGS = -std=c++11
LIBS += -lBulletDynamics -lBulletCollision -lLinearMath -lglut -lGLU
# Input
HEADERS +=../../src/physical_calculator/wheel.hpp \
 ../../src/physical_calculator/robot.hpp \
 ../../src/physical_calculator/physical_calculator.hpp \
  ../../src/physical_calculator/printable_mobile_object.hpp \
../../src/physical_calculator/position_data.hpp \
 ../../src/physical_calculator/dist_sensor.hpp \
 CommandLineArguments.h \
 DebugCastResult.h \
 DemoApplication.h \
 GLDebugDrawer.h \
 GLDebugFont.h \
 GL_DialogDynamicsWorld.h \
 GL_DialogWindow.h \
 GL_ShapeDrawer.h \
 GL_Simplex1to4.h \
 GlutDemoApplication.h \
 GlutStuff.h \
 RenderTexture.h \
 stb_image.h \
 Win32DemoApplication.h \
 test3d.hpp \

SOURCES += ../../src/physical_calculator/wheel.cpp \
 ../../src/physical_calculator/robot.cpp \
 ../../src/physical_calculator/physical_calculator.cpp \
 ../../src/physical_calculator/printable_mobile_object.cpp \
../../src/physical_calculator/position_data.cpp \
 ../../src/physical_calculator/dist_sensor.cpp \
 main.cpp \
 DemoApplication.cpp \
 GLDebugDrawer.cpp \
 GLDebugFont.cpp \
 GL_DialogDynamicsWorld.cpp \
 GL_DialogWindow.cpp \
 GL_ShapeDrawer.cpp \
 GL_Simplex1to4.cpp \
 GlutDemoApplication.cpp \
 GlutStuff.cpp \
 RenderTexture.cpp \
 stb_image.cpp \
 Win32AppMain.cpp \
 Win32DemoApplication.cpp \
 test3d.cpp \
