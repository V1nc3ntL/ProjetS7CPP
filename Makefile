CC=g++
CCFLAGS= -Wall -Werror -pedantic -std=c++17 -g
LIBFLAGS=
SRC_DIRS=app/
SRC=$(wildcard $(SRC_DIRS)*.cc) $(wildcard /.cpp)
OBJ=$(SRC:.cc=.o)
TST_DIR=tests/
TST=$(wildcard $(TST_DIR)/*.cc)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cc=.o)
EXEC= ProjetS7
.PHONY: clean all testcase distclean cleantest

all: $(EXEC)

testcase : 
	cd $(TST_DIR) ;  make

$(EXEC): $(OBJ)
	$(CC) $(LIBFLAGS) $^ -o $@  

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) $(EXEC)
cleantest:
	cd $(TST_DIR) ; make clean
	
distclean : clean cleantest

