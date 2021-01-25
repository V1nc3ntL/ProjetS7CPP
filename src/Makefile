#	Compilateur 
CC=g++
#	Options de compilation
CCFLAGS=-Wall -Werror -pedantic -std=c++17 -g -fmax-errors=4
#	librairies 
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
#	Ensemble des fichiers cc du projet
SRC= $(wildcard **/**/*.cc) $(wildcard **/*.cc) 

OBJ=$(SRC:.cc=.o)
OBJ_TEST= $(filter-out main.o, $(OBJ)) $(TST:.cc=.o)

EXEC= ProjetS7

.PHONY: clean all testcase distclean cleantest

all: $(EXEC)

testcase : 
	cd $(TST_DIR) ;  make

$(EXEC): $(OBJ)
	$(CC) $(CCFLAGS) $^ -o $@ $(LIB_PATH) $(LIBFLAGS) 

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depend:
	$(CC) $(CCFLAGS) -MM $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ) $(EXEC) vgcore*
cleantest:
	cd $(TST_DIR) ; make clean
	
distclean : clean cleantest

