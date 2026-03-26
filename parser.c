#include "push_swap.h"

static int	ft_atoi_ps(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		error_exit();
	while (*str)
	{
		if (*str < '0' || *str > '9')
			error_exit();
		res = res * 10 + (*str - '0');
		if (res * sign > 2147483647 || res * sign < -2147483648)
			error_exit();
		str++;
	}
	return ((int)(res * sign));
}

static void	check_duplicate(t_stack *a, int value)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->value == value)
			error_exit();
		tmp = tmp->next;
	}
}

static void	add_back(t_stack *a, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!new)
		error_exit();
	new->value = value;
	new->next = NULL;
	if (!a->top)
		a->top = new;
	else
	{
		tmp = a->top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	a->size++;
}

void	parse(t_stack *a, char **argv, int start)
{
	int	i;
	int	value;

	i = start;
	while (argv[i])
	{
		value = ft_atoi_ps(argv[i]);
		check_duplicate(a, value);
		add_back(a, value);
		i++;
	}
}