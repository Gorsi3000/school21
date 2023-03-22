CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

all: main clean

main: shared.o
	$(CC) $(CFLAGS) shared.o -o ../build/main

shared.o: shared.c
	$(CC) $(CFLAGS) -c shared.c -o shared.o

clean:
	rm *.o

rebuild:
	clean all