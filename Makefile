NAME = 		push_swap
CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror

SRC = 		main.c parser.c error.c free.c index.c \
			disorder.c algorithm_simple.c algorithm_medium.c \
			algorithm_complex.c algorithm_adaptive.c \
			operations_swap.c operations_push.c operations_rotate.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all