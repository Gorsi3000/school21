CC := gcc
CFLAGS := -Wall -Wextra -Werror -c
LFLAGS := -Wall -Wextra -Werror -o
BUILD_DIR := ../build/
SRC_DIR := ./
OBJ_DIR	:= ./obj/
SRC_FILES = math_func.c# run_test.c stack.c tree.c input.c

OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: test_tokens_src test_transform_to_rpn

test_tokens_src: obj $(eval SRC_FILES = math_func.c input.c test_tokens.c)

test_tokens: test_tokens_src ${OBJS} 
	${CC} ${LFLAGS} ${BUILD_DIR}$@ ${OBJS}

test_transform_to_rpn_src: obj $(eval SRC_FILES = math_func.c stack.c tree.c input.c test_transform_to_rpn.c)

test_transform_to_rpn: test_transform_to_rpn_src ${OBJS}
	${CC} ${LFLAGS} ${BUILD_DIR}$@ ${OBJS}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	$(CC) $(CFLAGS) $< -o $@

# $(OBJ_DIR)%.o: $(SRC_DIR)%.c# $(SRC_DIR)%.h
# 	$(CC) $(CFLAGS) $< -o $@

obj: 
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BUILD_DIR)

rebuild: clean all

clean:
	 rm -rf $(OBJ_DIR)
	 rm -f ${BUILD_DIR}*

vars: test_transform_to_rpn_src
	echo ${SRCS}
	echo ${OBJS}
	
	