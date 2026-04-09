/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:20:22 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/09 12:48:12 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_counts *c)
{
	t_node	*first;
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	first->next = NULL;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	if (c->bench < 1)
		write(1, "ra\n", 3);
	c->count_ra++;
	c->count_total++;
}

void	rb(t_stack *b, t_counts *c)
{
	t_node	*first;
	t_node	*last;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	b->top = first->next;
	first->next = NULL;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	if (c->bench < 1)
		write(1, "rb\n", 3);
	c->count_rb++;
	c->count_total++;
}

void	rr(t_stack *a, t_stack *b, t_counts *c)
{
	ra(a, c);
	rb(b, c);
	if (c->bench < 1)
		write(1, "rr\n", 3);
	c->count_rr++;
	c->count_total++;
}
