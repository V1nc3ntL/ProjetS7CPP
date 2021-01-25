CC=g++
CCFLAGS=-Wall -Werror -pedantic -std=c++17 -g
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SRC_DIRS= app graphic gameLogic graphic/GIs
SRC= $(wildcard **/*.cc) 
OBJ=$(SRC:.cc=.o)
TST_DIR=tests/
TST=$(wildcard $(TST_DIR)/*.cc)
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
	rm -f $(OBJ) $(EXEC)
cleantest:
	cd $(TST_DIR) ; make clean
	
distclean : clean cleantest

