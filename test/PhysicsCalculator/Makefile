CC=g++
CFLAGS= -W -Wall -Wextra
INCLUDES=-I/usr/local/include/bullet
LDFLAGS= -lBulletDynamics -lBulletCollision -lLinearMath
LIBRAIRIES= -L/usr/local/lib

SRC= main.cpp physics_calculator.cpp
OBJ=$(SRC:.cpp=.o) 
EXEC=moteur

all: $(EXEC)

$(EXEC): $(OBJ) 
	@echo "================================================================================"
	@echo ":> Linking $^ to $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBRAIRIES) $(LDFLAGS)

%.o: %.cpp
	@echo "................................................................................"
	@echo ":> Compiling: \t $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

.PHONY: all

clean:
	@echo ":> Cleanning ..."
	@rm -rf *.o $(EXEC)
