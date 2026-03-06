NAME		=	push_swap

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I./include
RM			=	rm -f

SRCS		=	src/push_swap.c \
				src/parsing/parse_input.c \
				src/parsing/parse_args.c \
				src/parsing/parse_utils.c \
				src/parsing/parse_validate.c \
				src/error/check_duplicates.c \
				src/error/check_errors.c \
				src/error/error.c \
				src/utils/ft_atoi_safe.c \
				src/utils/ft_atol.c \
				src/stack/stack_utils.c \
				src/stack/stack_utils2.c

OBJS		=	$(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
