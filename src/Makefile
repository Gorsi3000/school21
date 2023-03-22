CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

all: main clean

main: main.o
	$(CC) $(CFLAGS) main.o -o ../build/main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm *.o

rebuild:
	clean all