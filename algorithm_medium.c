/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:19:21 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/06 19:45:49 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium_sort(t_stack *a, t_stack *b, t_counts *c)
{
	int	chunk;
	int	i;

	chunk = a->size / 6;
	i = 0;
	while (a->size)
	{
		if (a->top->index <= i && ++i)
		{
			pb(a, b, c);
			rb(b, c);
		}
		else if (a->top->index <= i + chunk && ++i)
			pb(a, b, c);
		else
			ra(a, c);
	}
	while (b->size)
	{
		move_max_to_top_b(b, c);
		pa(a, b, c);
	}
}
