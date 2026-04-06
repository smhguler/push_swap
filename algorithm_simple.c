/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:19:26 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/06 19:36:50 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b_by_range(t_stack *a, t_stack *b, t_counts *c)
{
	int	i;
	int	range;

	i = 0;
	if (a->size > 100)
		range = 35;
	else
		range = 15;
	while (a->size > 3)
	{
		if (a->top->index <= i)
		{
			pb(a, b, c);
			rb(b, c);
			i++;
		}
		else if (a->top->index <= i + range)
		{
			pb(a, b, c);
			i++;
		}
		else
			ra(a, c);
	}
}

void	simple_sort(t_stack *a, t_stack *b, t_counts *c)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 3)
		return (sort_three(a, c));
	if (a->size <= 5)
		return (sort_five(a, b, c));
	push_to_b_by_range(a, b, c);
	sort_three(a, c);
	while (b->size)
	{
		move_max_to_top_b(b, c);
		pa(a, b, c);
	}
}
