CC=g++
CFLAGS= -W -Wall -Wextra -std=c++11 -g -O0
INCLUDE= -I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtXml -I/usr/include/qt5/QtXmlPatterns -fPIC
LDFLAGS=

SRC= xml_parser.cpp
OBJ= $(SRC:.cpp=.o)

all: $(OBJ)

$(EXEC): $(OBJ)
	@echo "Linking\t$^ in\t[$@]"
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@echo "Compiling\t$@"
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

.PHONY: clean

clean:
	@echo "Cleaning xml_parser binaries"
	@rm -rf *.o $(EXEC)

