CC := gcc
CFLAGS := -Wall -Werror -Wextra -c
LFLAGS := -Wall -Werror -Wextra -o
BUILD_DIR := ../build/
SRC_DIR := ./
OBJ_DIR	:= ./obj/
SRC_FILES = print_module.c main_module_entry_point.c

OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
PM := print_module main_module_entry_point

all: obj print_module check

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -o $@ $<

obj: 
	@mkdir -p $(OBJ_DIR)

print_module: obj print_module.h $(OBJS)
	${CC} ${LFLAGS} ${BUILD_DIR}Quest_1 $(OBJS)


rebuild: clean all

check:
	@cp ../materials/linters/.clang-format .
	clang-format -i *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem ./*c

vars:
	echo ${OBJS}

.PHONY: all clean rebuild