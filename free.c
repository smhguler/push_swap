/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:19:43 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/07 18:27:12 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	free(stack);
}

void	reset_counts(t_counts *c)
{
	c->count_total = 0;
	c->count_sa = 0;
	c->count_sb = 0;
	c->count_ss = 0;
	c->count_pa = 0;
	c->count_pb = 0;
	c->count_ra = 0;
	c->count_rb = 0;
	c->count_rr = 0;
	c->count_rra = 0;
	c->count_rrb = 0;
	c->count_rrr = 0;
}
