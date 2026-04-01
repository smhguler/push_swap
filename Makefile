NAME =		push_swap
CC =		cc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f

HEADER =	push_swap.h
SRC =		main.c parser.c error.c free.c index.c benchmark.c\
			disorder.c adaptive.c algorithm_simple.c \
			algorithm_medium.c algorithm_complex.c \
			operations_swap.c operations_push.c \
			operations_rotate.c operations_reverse_rotate.c
OBJ =		$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re