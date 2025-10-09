CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror -g
OBJ = main.o copy.o direction.o enemy.o laser.o LinkedList.o map.o menu.o move.o ucpSleep.o
EXEC = laserTank

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c copy.h direction.h enemy.h laser.h LinkedList.h map.h menu.h move.h ucpSleep.h
	$(CC) $(CFLAGS) -c main.c

copy.o : copy.c copy.h
	$(CC) $(CFLAGS) -c copy.c

direction.o : direction.c direction.h
	$(CC) $(CFLAGS) -c direction.c

enemy.o : enemy.c enemy.h
	$(CC) $(CFLAGS) -c enemy.c

laser.o : laser.c laser.h
	$(CC) $(CFLAGS) -c laser.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFlAGS) -c LinkedList.c

map.o : map.c map.h
	$(CC) $(CFLAGS) -c map.c

menu.o : menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c

move.o : move.c move.h
	$(CC) $(CFLAGS) -c move.c

ucpSleep.o : ucpSleep.c ucpSleep.h
	$(CC) $(CFLAGS) -c ucpSleep.c

clean:
	rm -f $(OBJ) $(EXEC) *.o

