MAKE=make -C src/ && cp src/ProjetS7 .
CLEAN=make clean -C src/ && rm *.o *.swp ProjetS7
all:
	$(MAKE)
clean:
	$(CLEAN)
