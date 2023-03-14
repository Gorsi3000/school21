SHELL=bash
BUILD_PATH=../build/
SRC_PATH=./data_module/ ./data_libs/
TARGET=${BUILD_PATH}Quest_3
CC=gcc
SRCS= $(wildcard $(patsubst %, %*.c, ${SRC_PATH}))
OBJS=$(patsubst %.c, ${BUILD_PATH}%.o, $(notdir ${SRCS}))
FLAGS=-Wall -Wextra -Werror

vpath %.c ./data_module:./data_libs

all: ${TARGET} clang cppcheck

${TARGET}: ${OBJS}
	${CC} ${FLAGS} $^ -o $@

${BUILD_PATH}%.o : %.c
	${CC} -c ${FLAGS} ${SRC_PATH:%=-I%} $^ -o $@

cppcheck:
	cppcheck ${SRCS}

clang: copy_format
	clang-format -i ${SRC_PATH}*.h
	clang-format -i ${SRC_PATH}*.c

copy_format:
	cp ../materials/linters/.clang-format .

build:
	mkdir ${BUILD_PATH}

clean:
	rm ${BUILD_PATH}*.o

rebuild: clean all

vars:
	echo srcs=${SRC_PATH:%=-L% -I%}