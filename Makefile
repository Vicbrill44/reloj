all: clock

clock: main.o display.o
	gcc main.o display.o -o clock -l ncurses 

main.o: main.c display.h
	gcc -c main.c

display.o: display.c display.h
	gcc -c display.c

clean:
	rm -f *.o clock

run:
	./clock.sh | ./clock
