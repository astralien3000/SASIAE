CC=g++
CFLAGS= -W -Wall -Wextra -std=c++11 -I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtXml -fPIC
LDFLAGS=

SRC= xml_parser.cpp
OBJ= $(SRC:.cpp=.o)

all: $(OBJ)

$(EXEC): $(OBJ)
	@echo "Linking\t$^ in\t[$@]"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@echo "Compiling\t$@"
	@$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	@echo "Cleaning xml_parser binaries"
	@rm -rf *.o $(EXEC)

