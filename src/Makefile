CC := gcc 
LFLAGS := -Wall -Wextra -Werror -o
CFLAGS := -Wall -Wextra -Werror -c
BUILD_DIR := ../build/
OBJ_DIR := ./obj/
SRCS := list_test.c list.c stack_test.c stack.c
OBJ_FILES := ${SRCS:.c=.o}
OBJS = $(addprefix ${OBJ_DIR}, ${OBJ_FILES})
H := list.h stack.h

all: obj list_test stack_test# check

obj: $(SRCS)
	@mkdir -p $(OBJ_DIR)

list_test: $(wildcard list*)
	${CC} ${LFLAGS} ${BUILD_DIR}Quest_2 ${OBJS}

vars:
	echo $(OBJS)

stack_test: $(wildcard stack*)
	${CC} ${LFLAGS} ${BUILD_DIR}Quest_3 ${OBJS}

${OBJS}: ${SRCS}
	${CC} ${CFLAGS} $@ $<

clean:
	rm -f ${BUILD_DIR}*
	rm -fr {OBJ_DIR}

check:
	@cp ../materials/linters/.clang-format .
	clang-format -i ${H} 
	clang-format -i ${SRCS}
	cppcheck --enable=all

rebuild: clean all

.PHONY: clean all rebuild