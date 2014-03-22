CC=g++
CFLAGS= -W -Wall -Wextra -std=c++11 -g -O0
INCLUDE= -I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtXml -I/usr/include/qt5/QtXmlPatterns -I/usr/include/qt5/QtGui -fPIC
LDFLAGS= -lQt5Core -lQt5Xml -L/home/hugo/Qt/5.2.0/gcc_64/lib/ -lQt5XmlPatterns

SRC= ../../../src/coordinator/xml_parser/xml_parser.cpp test_xml_parser.cpp ../../../src/common/object_config.cpp ../../../src/common/position_data.cpp
OBJ= $(SRC:.cpp=.o)
EXEC= test_xml_parser

all: test 

test: $(EXEC)
	@echo "======================================================"
	@echo "====================== Testing ======================="
	@./test_xml_parser
	@echo "======================================================"

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

