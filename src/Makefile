CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

all: main clean

main: modules_db.o
	$(CC) $(CFLAGS) modules_db.o -o ../build/main

modules_db.o: modules_db.c
	$(CC) $(CFLAGS) -c modules_db.c -o modules_db.o

clean:
	rm *.o

rebuild:
	clean all