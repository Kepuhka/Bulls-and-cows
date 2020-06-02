CCFLAGS = -Wall -Wextra `pkg-config --cflags --libs gtk+-2.0`
TEST = build/test
SRC = build/src
CC = gcc
OBJECT = number_splitting_test.o game_number_test.o string_test.o reading_file_test.o strtok_string_test.o check_user_word_test.o word_comparison_test.o

all: comp

comp: $(SRC)/main.o $(SRC)/number.o $(SRC)/word.o $(SRC)/func.o
	$(CC) -Wall -Wextra $(SRC)/main.o $(SRC)/number.o $(SRC)/word.o $(SRC)/func.o -o main `pkg-config --cflags --libs gtk+-2.0`

$(SRC)/main.o: src/main.c
	$(CC) $(CCFLAGS) -c src/main.c -o $(SRC)/main.o

$(SRC)/number.o: src/number.c
	$(CC) $(CCFLAGS) -c src/number.c -o $(SRC)/number.o

$(SRC)/word.o: src/word.c
	$(CC) $(CCFLAGS) -c src/word.c -o $(SRC)/word.o

$(SRC)/func.o: src/func.c
	$(CC) $(CCFLAGS) -c src/func.c -o $(SRC)/func.o

test: $(TEST)/test
	$(TEST)/test

$(TEST)/test: $(TEST)/number.o $(TEST)/word.o $(TEST)/func.o $(TEST)/main.o $(TEST)/number_splitting_test.o $(TEST)/game_number_test.o $(TEST)/string_test.o $(TEST)/reading_file_test.o $(TEST)/strtok_string_test.o $(TEST)/check_user_word_test.o $(TEST)/word_comparison_test.o
	cd build/test;\
	$(CC) -Wall -Wextra $(OBJECT) main.o number.o word.o func.o -o test `pkg-config --cflags --libs gtk+-2.0`

$(TEST)/number.o: src/number.c
	$(CC) $(CCFLAGS) -c src/number.c -o $(TEST)/number.o

$(TEST)/word.o: src/word.c
	$(CC) $(CCFLAGS) -c src/word.c -o $(TEST)/word.o

$(TEST)/func.o: src/func.c
	$(CC) $(CCFLAGS) -c src/func.c -o $(TEST)/func.o

$(TEST)/main.o: test/main.c
	$(CC) $(CCFLAGS) -c test/main.c -o $(TEST)/main.o

$(TEST)/number_splitting_test.o: test/number_splitting_test.c
	$(CC) $(CCFLAGS) -c test/number_splitting_test.c -o $(TEST)/number_splitting_test.o

$(TEST)/game_number_test.o: test/game_number_test.c
	$(CC) $(CCFLAGS) -c test/game_number_test.c -o $(TEST)/game_number_test.o

$(TEST)/string_test.o: test/string_test.c 
	$(CC) $(CCFLAGS) -c test/string_test.c -o $(TEST)/string_test.o

$(TEST)/reading_file_test.o: test/reading_file_test.c
	$(CC) $(CCFLAGS) -c test/reading_file_test.c -o $(TEST)/reading_file_test.o

$(TEST)/strtok_string_test.o: test/strtok_string_test.c
	$(CC) $(CCFLAGS) -c test/strtok_string_test.c -o $(TEST)/strtok_string_test.o

$(TEST)/check_user_word_test.o: test/check_user_word_test.c
	$(CC) $(CCFLAGS) -c test/check_user_word_test.c -o $(TEST)/check_user_word_test.o

$(TEST)/word_comparison_test.o: test/word_comparison_test.c
	$(CC) $(CCFLAGS) -c test/word_comparison_test.c -o $(TEST)/word_comparison_test.o

install: 
	cd build/test;\
	./test

clean:
	cd build/test;\
	rm -f test *.o
	cd build/src;\
	rm -f *.o