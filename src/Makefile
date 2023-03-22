CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

all: build_db clean

build_db: modules_db.o master_modules.o master_levels.o master_status_events.o
	clang-format -n *.c
	clang-format -n *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	$(CC) $(CFLAGS) modules_db.o master_modules.o master_levels.o master_status_events.o -o ../build/main

modules_db.o: modules_db.c
	$(CC) $(CFLAGS) -c modules_db.c -o modules_db.o

master_modules.o: master_modules.c
	$(CC) $(CFLAGS) -c master_modules.c -o master_modules.o

master_levels.o: master_levels.c
	$(CC) $(CFLAGS) -c master_levels.c -o master_levels.o

master_status_events.o: master_status_events.c
	$(CC) $(CFLAGS) -c master_status_events.c -o master_status_events.o

clean:
	rm *.o

rebuild:
	clean all