all: telephone-keypad

telephone-keypad: main.c
	gcc main.c -o telephone-keypad -lncurses
	
.PHONY: clean

clean:
	rm -f *.o
	rm -f telephone-keypad
