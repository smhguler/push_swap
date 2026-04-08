/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:19:26 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/08 17:11:02 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack *a, t_stack *b, t_counts *c)
{
	int		min;
	t_node	*tmp;

	if (a->size <= 5)
		sorting(a, b, c);
	else
	{
		while (a->size)
		{
			tmp = a->top;
			min = tmp->value;
			while (tmp)
			{
				if (tmp->value < min)
					min = tmp->value;
				tmp = tmp->next;
			}
			while (a->top->value != min)
				ra(a, c);
			pb(a, b, c);
		}
		while (b->size)
			pa(a, b, c);
	}
}
