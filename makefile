
# makefile 3

CFLAGS = -02
DEBUGFLAGS = -g -Wall -Wextra

program: main.o funcs.o
	g++ ${CFLAGS} main.o funcs.o -o program

.PHONY: debug clean
debug: CFLAGS=${DEBUGFLAGS}
debug: program

main.o: main.cpp funcs.h
	g++ ${CFLAGS} -c main.cpp

funcs.o: funcs.cpp funcs.h
	g++ ${CFLAGS} -c funcs.cpp
clean
	-@rm -f program
	-@rm -f *.o
	
