SHELL=bash
BUILD_PATH=./build/ 
SRC_PATH=./src/data_module ./src/data_libs
TARGET=${BUILD_PATH}MyProject
CC=gcc
SRCS=$(wildcard *.c)
OBJS=$(subst ${SRC_PATH}, ${BUILD_PATH}, ${SRCS:.c=.o})
FLAGS=${-Wall -Wextra -Werror} 

all: ${TARGET} clang cppcheck

${TARGET}: ${OBJS}
	${CC} $< -o $@

${BUILD_PATH}%.o: ${SRC_PATH}%.c build
	${CC} -c ${FLAGS} $< -o $@

cppcheck:
	cppcheck ${SRC_PATH}${SRCS}

clang:
	clang-format -i ${BUILD_PATH}${SRCS}

build:
	mkdir ${BUILD_PATH}

clean:
	rm -fr ${BUILD_PATH}

vars:
	echo "srcs=${SRCS}"
	echo "src=%.c"
