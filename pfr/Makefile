CC=gcc
CFLAGS=-I.

robot: main.o robot.o 
	$(CC) -o robot main.o robot.o $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

robot.o: robot.c
	$(CC) -c robot.c $(CFLAGS)

clean:
	rm -f *.o robot
