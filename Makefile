
.PHONY:		all clean install uninstall reinstall

NAME := ./snake

SRC_PATH :=	src/
INC_PATH :=	includes/

CC := clang
LIBS := -lncurses
FLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic

SRCS = $(addprefix $(SRC_PATH), $(FILES))

FILES := snake.c \
		main_algo.c \
		snake_init.c \
		functional.c \

all: install

install :
	$(CC) $(FLAGS) $(LIBS) $(SRCS) -I $(INC_PATH) -o $(NAME)
		
uninstall :
	rm -rf $(NAME)

clean:
	rm -rf *.o $(NAME)

reinstall: clean install

push: uninstall
	rm records.txt