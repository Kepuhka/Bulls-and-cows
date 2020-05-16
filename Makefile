all:
	gcc src/*.c -o main `pkg-config --cflags --libs gtk+-2.0`