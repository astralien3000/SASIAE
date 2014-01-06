CXX=g++
CXXFLAGS=-Wall
LDFLAGS=-I/usr/include/qt4/ -lQtCore -lQtGui
EXEC=testmainwindow
OBJ=main.o

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.cpp ui_mainwindow.h mainwindow.h
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)

clean:
	rm $(OBJ) $(EXEC) *~