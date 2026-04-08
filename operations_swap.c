/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:20:26 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/08 19:23:36 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_counts *c)
{
	t_node	*f;
	t_node	*s;

	if (!a || a->size < 2)
		return ;
	f = a->top;
	s = f->next;
	f->next = s->next;
	s->next = f;
	a->top = s;
	if (c->bench != 1)
		write(1, "sa\n", 3);
	c->count_sa++;
	c->count_total++;
}

void	sb(t_stack *b, t_counts *c)
{
	t_node	*f;
	t_node	*s;

	if (!b || b->size < 2)
		return ;
	f = b->top;
	s = f->next;
	f->next = s->next;
	s->next = f;
	b->top = s;
	if (c->bench != 1)
		write(1, "sb\n", 3);
	c->count_sb++;
	c->count_total++;
}

void	ss(t_stack *a, t_stack *b, t_counts *c)
{
	sa(a, c);
	sb(b, c);
	if (c->bench != 1)
		write(1, "ss\n", 3);
	c->count_ss++;
	c->count_total++;
}
