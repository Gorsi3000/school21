CC := gcc
CFLAGS := -Wall -Werror -Wextra -c
LFLAGS := -Wall -Werror -Wextra -o
BUILD_DIR := ../build/
SRC_DIR := .
OBJ_DIR	:= ./obj/
SRC_FILES = s21_string.c \
		 s21_string_test.c \
		 main.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
HEADER := -I includes/

all: obj $(NAME)

obj: $(SRCS)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@ $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(LFLAGS) $(NAME) $(OBJS) $(HEADER)

clean:
	 rm -rf $(OBJ_DIR)
	 rm -f $(NAME)

rebuid: clean all

.PHONY: all clean rebuild