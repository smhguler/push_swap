/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:20:00 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/07 18:27:22 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		idx;

	i = a->top;
	while (i)
	{
		idx = 0;
		j = a->top;
		while (j)
		{
			if (j->value < i->value)
				idx++;
			j = j->next;
		}
		i->index = idx;
		i = i->next;
	}
}
