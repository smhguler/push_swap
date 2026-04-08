/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:20:13 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/08 17:30:20 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, t_counts *c)
{
	t_node	*tmp;

	if (!b || !b->top)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = a->top;
	a->top = tmp;
	a->size++;
	b->size--;
	if (c->bench != 1)
		write(1, "pa\n", 3);
	c->count_pa++;
	c->count_total++;
}

void	pb(t_stack *a, t_stack *b, t_counts *c)
{
	t_node	*tmp;

	if (!a || !a->top)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = b->top;
	b->top = tmp;
	a->size--;
	b->size++;
	if (c->bench != 1)
		write(1, "pb\n", 3);
	c->count_pb++;
	c->count_total++;
}
