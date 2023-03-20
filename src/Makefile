CC := gcc
CFLAGS := -std=c11 -c -g
LFLAGS := -std=c11 -o
BUILD_DIR := ../build/
SRC_DIR := ./
OBJ_DIR	:= ./obj/
SRC_FILES = graph.c math_func.c stack.c input.c output.c\
			lexer.c mem.c

OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: graph

graph: obj ${SRCS} ${OBJS} ./lexema.h
	${CC} ${LFLAGS} ${BUILD_DIR}$@ ${OBJS} 
#$(OBJ_DIR)math_func.o $(OBJ_DIR)stack.o $(OBJ_DIR)input.o\
									# $(OBJ_DIR)lexer.o $(OBJ_DIR)graph.o $(OBJ_DIR)output.o $(OBJ_DIR)mem.o
# lexer: obj ${OBJS} ./lexema.h
# 	${CC} ${LFLAGS} ${BUILD_DIR}$@ $(OBJ_DIR)math_func.o $(OBJ_DIR)stack.o $(OBJ_DIR)input.o\
# 									$(OBJ_DIR)lexer.o $(OBJ_DIR)output.o

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

vars: test_tokens_src
	echo ${SRCS}
	echo ${OBJS}
	
	