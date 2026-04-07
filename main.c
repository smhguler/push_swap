/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:15:10 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/07 18:27:31 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_all(t_stack **a, t_stack **b, t_counts *c)
{
	*a = init_stack();
	*b = init_stack();
	reset_counts(c);
}

static int	parse_options(int argc, char **argv, int *mode, int *bench)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			*bench = 1;
		else if (ft_strcmp(argv[i], "--simple") == 0 || ft_strcmp(argv[i],
				"--medium") == 0 || ft_strcmp(argv[i], "--complex") == 0
			|| ft_strcmp(argv[i], "--adaptive") == 0)
			*mode = strategy_selector(argv[i]);
		else
			return (i);
		i++;
	}
	return (i);
}

static void	execute_sort(t_stack *a, t_stack *b, t_counts *c, int mode)
{
	if (mode == 0)
		simple_sort(a, b, c);
	else if (mode == 1)
		medium_sort(a, b, c);
	else if (mode == 2)
		complex_sort(a, b, c);
	else
		adaptive_sort(a, b, c);
}

int	main(int argc, char **argv)
{
	t_main_vars	var;

	if (argc < 2)
		return (0);
	var.mode = 3;
	var.bench = 0;
	init_all(&var.a, &var.b, &var.c);
	var.i = parse_options(argc, argv, &var.mode, &var.bench);
	parse(var.a, argv, var.i);
	assign_index(var.a);
	var.disorder = compute_disorder(var.a);
	if (!is_sorted(var.a))
		execute_sort(var.a, var.b, &var.c, var.mode);
	print_benchmark(&var.c, var.bench, var.mode, var.disorder);
	free_stack(var.a);
	free_stack(var.b);
	return (0);
}
