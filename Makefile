all: telephone-keypad

telephone-keypad: telephone-keypad.c
	gcc telephone-keypad.c -o telephone-keypad -lncurses
	
.PHONY: clean

clean:
	rm -f *.o
	rm -f telephone-keypad
