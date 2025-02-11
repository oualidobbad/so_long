SRC = *.c $(wildcard map/*.c) GNL/get_next_line.c GNL/get_next_line_utils.c 
NAME = so_long
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(SRC)
	@cc $(FLAGS) $^ -o $@
clean:
	@rm -rf $(NAME)
re: clean all 

.PHONY: clean all re
