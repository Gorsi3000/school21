CC := gcc 
FLAGS := -Wall -Wextra -Werror
BUILD_DIR := ../build/
SRCS := list_test.c list.c
H := list.h

all: list_test# check

list_test: ${H}
	${CC} ${FLAGS} -o ${BUILD_DIR}$@ ${SRCS}

clean:
	rm -f ${BUILD_DIR}*

check:
	@cp ../materials/linters/.clang-format .
	clang-format -i ${H} 
	clang-format -i ${SRCS}
	cppcheck --enable=all

rebuild: clean all

.PHONY: clean all rebuild