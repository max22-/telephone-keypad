all: telephone-keypad

timer.o: timer.c timer.h
	gcc -o timer.o -c timer.c -Wall
	
state-machine.o: state-machine.c state-machine.h
	gcc -o state-machine.o -c state-machine.c -Wall

telephone-keypad.o: telephone-keypad.c timer.h
	gcc -o telephone-keypad.o -c telephone-keypad.c -Wall

telephone-keypad: telephone-keypad.o timer.o state-machine.o
	gcc -o telephone-keypad telephone-keypad.o timer.o state-machine.o -lncurses
	
.PHONY: clean

clean:
	rm -f *.o
	rm -f telephone-keypad
