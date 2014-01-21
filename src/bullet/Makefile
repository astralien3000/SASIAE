CC=g++
CFLAGS= -W -Wall -Wextra
INCLUDES=-I/usr/include/bullet
LDFLAGS= -lBulletDynamics -lBulletCollision -lLinearMath
LIBRAIRIES= -L/usr/lib64/

SRC= projetTestv1.cpp
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
