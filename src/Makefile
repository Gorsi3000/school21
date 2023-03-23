CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

all: build_db clean

build_db: modules_db.o master_modules.o master_levels.o\
			 master_status_events.o shared.o crudl.o
	$(CC) $(CFLAGS) @^ -o ../build/main

crudl.o: crudl.c entity.h
modules_db.o: modules_db.c
	$(CC) $(CFLAGS) -c modules_db.c -o modules_db.o

master_modules.o: master_modules.c
	$(CC) $(CFLAGS) -c master_modules.c -o master_modules.o

master_levels.o: master_levels.c
	$(CC) $(CFLAGS) -c master_levels.c -o master_levels.o

master_status_events.o: master_status_events.c
	$(CC) $(CFLAGS) -c master_status_events.c -o master_status_events.o

shared.o: shared.c
	$(CC) $(CFLAGS) -c shared.c -o shared.o

format:
	clang-format -i *.c
	clang-format -i *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

clean:
	rm *.o

rebuild:
	clean all