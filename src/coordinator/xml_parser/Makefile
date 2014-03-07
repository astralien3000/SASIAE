CC=g++
CFLAGS= -W -Wall -Wextra -std=c++0x -I/usr/include/qt5 -I/usr/include/qt5/QtCore
LDFLAGS=

SRC= xml_parser.cpp text_xml_parser.cpp
OBJ= $(SRC:.cpp=.o)
EXEC=test_xml_parser

all: $(EXEC)

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

