UNAME=$(shell uname)

CCFLAGS=-Wextra -Wredundant-decls -O3 `pkg-config --cflags --libs gtk+-2.0`
CC=gcc
OBJECT=number_splitting_test.o game_number_test.o string_test.o reading_file_test.o strtok_string_test.o
DIR=cd build/test;

all:
	gcc src/*.c -o main `pkg-config --cflags --libs gtk+-2.0`

test: comp install

comp: object
	$(DIR)\
	$(CC) $(LDFLAGS) $(OBJECT) main.o ../src/func.o -o test `pkg-config --cflags --libs gtk+-2.0`
	
install:
	cd build/test;\
	./test

object: clean ctest/ctest.h
	$(CC) $(CCFLAGS) -c -o build/test/main.o test/main.c
	$(CC) $(CCFLAGS) -c -o build/test/game_number_test.o test/game_number_test.c
	$(CC) $(CCFLAGS) -c -o build/test/number_splitting_test.o test/number_splitting_test.c
	$(CC) $(CCFLAGS) -c -o build/test/string_test.o test/string_test.c
	$(CC) $(CCFLAGS) -c -o build/src/func.o src/func.c
	$(CC) $(CCFLAGS) -c -o build/test/reading_file_test.o test/reading_file_test.c
	$(CC) $(CCFLAGS) -c -o build/test/strtok_string_test.o test/strtok_string_test.c

clean:
	cd build/test;\
	rm -f test *.o
	cd build/src;\
	rm -f *.o