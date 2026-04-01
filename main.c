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

static int	strategy_selector(char *arg)
{
	if (!arg)
		return (4);
	if (ft_strcmp(arg, "--simple") == 0)
		return (0);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (2);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (3);
	return (4);
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
	t_stack		*a;
	t_stack		*b;
	t_counts	c;
	int			mode;
	int			bench_mode;
	int			i;
	double		disorder;

	mode = 3;
	i = 1;
	bench_mode = 0;
	reset_counts(&c);
	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	while (i < argc && argv[i][0] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			bench_mode = 1;
		else if (ft_strcmp(argv[i], "--simple") == 0
			|| ft_strcmp(argv[i], "--medium") == 0
			|| ft_strcmp(argv[i], "--complex") == 0
			|| ft_strcmp(argv[i], "--adaptive") == 0)
			mode = strategy_selector(argv[i]);
		else
			break ;
		i++;
	}
	parse(a, argv, i);
	assign_index(a);
	disorder = compute_disorder(a);
	if (!is_sorted(a))
	{
		if (mode == 0)
			simple_sort(a, b, &c);
		else if (mode == 1)
			medium_sort(a, b, &c);
		else if (mode == 2)
			complex_sort(a, b, &c);
		else if (mode == 3)
			adaptive_sort(a, b, &c);
	}
	print_benchmark(&c, bench_mode, mode, disorder);
	free_stack(a);
	free_stack(b);
	return (0);
}
