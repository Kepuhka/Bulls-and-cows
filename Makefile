UNAME=$(shell uname)

CCFLAGS=-Wextra -Wredundant-decls -O3 `pkg-config --cflags --libs gtk+-2.0`
CC=gcc

all:
	gcc src/*.c -o main `pkg-config --cflags --libs gtk+-2.0`

test: object
	cd build/test;\
	$(CC) $(LDFLAGS) main.o ../src/func.o game_number_test.o -o test `pkg-config --cflags --libs gtk+-2.0`

object: clean ctest/ctest.h
	$(CC) $(CCFLAGS) -c -o build/test/main.o test/main.c
	$(CC) $(CCFLAGS) -c -o build/test/game_number_test.o test/game_number_test.c
	$(CC) $(CCFLAGS) -c -o build/src/func.o src/func.c

clean:
	cd build/test;\
	rm -f test *.o
	cd build/src;\
	rm -f *.o