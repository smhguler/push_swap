NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude

SRC = \
	push_swap.c \
	src/algorithms/adaptive_sort.c \
	src/algorithms/disorder.c \
	src/algorithms/medium_sort.c \
	src/algorithms/radix_sort.c \
	src/algorithms/simple_sort.c \
	src/error/check_duplicates.c \
	src/error/check_errors.c \
	src/error/error.c \
	src/operations/push.c \
	src/operations/reverse_rotate.c \
	src/operations/rotate.c \
	src/operations/swap.c \
	src/parsing/parse_args.c \
	src/parsing/parse_input.c \
	src/parsing/parse_utils.c \
	src/parsing/parse_validate.c \
	src/stack/stack_utils.c \
	src/stack/stack_utils2.c \
	src/utils/ft_atoi_safe.c \
	src/utils/ft_atol.c \
	src/utils/medium_sort_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re