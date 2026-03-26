#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int	get_mode(char *arg)
{
	if (!arg)
		return (3);
	if (ft_strcmp(arg, "--simple") == 0)
		return (0);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (2);
	return (3);
}

static int	is_sorted(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static t_stack	*init_stack(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		error_exit();
	s->top = NULL;
	s->size = 0;
	return (s);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		mode;
	int		start;

	if (argc < 2)
		return (0);
	mode = get_mode(argv[1]);
	start = (mode != 3);
	a = init_stack();
	b = init_stack();
	parse(a, argv, start + 1);
	assign_index(a);
	if (!is_sorted(a))
	{
		if (mode == 0)
			simple_sort(a, b);
		else if (mode == 1)
			medium_sort(a, b);
		else if (mode == 2)
			complex_sort(a, b);
		else
			adaptive_sort(a, b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
