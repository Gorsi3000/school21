CC := gcc
CFLAGS := -Wall -Wextra -Werror -c
LFLAGS := -Wall -Wextra -Werror -o
BUILD_DIR := ../build/
SRC_DIR := ./
OBJ_DIR	:= ./obj/
SRC_FILES = math_func.c run_test.c stack.c tree.c

OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: run_test

run_test: ${OBJS}
	${CC} ${LFLAGS} ${BUILD_DIR}$@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c #$(SRC_DIR)%.h
	$(CC) $(CFLAGS) $< -o $@

obj: 
	mkdir -p $(OBJ_DIR)

test_lexer:
	${CC} ${LFLAGS}  