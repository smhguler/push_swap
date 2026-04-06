/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:49:06 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/06 19:44:13 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top_a(t_stack *a, t_counts *c)
{
	t_node	*tmp;
	int		min;
	int		pos;
	int		i;

	tmp = a->top;
	min = tmp->value;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (pos <= a->size / 2)
		while (a->top->value != min)
			ra(a, c);
	else
		while (a->top->value != min)
			rra(a, c);
}

void    move_max_to_top_b(t_stack *b, t_counts *c)
{
    t_node  *tmp;
    int     max_idx;
    int     pos;
    int     i;

    tmp = b->top;
    max_idx = tmp->index;
    pos = 0;
    i = 0;
    while (tmp)
    {
        if (tmp->index > max_idx)
        {
            max_idx = tmp->index;
            pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    if (pos <= b->size / 2)
        while (b->top->index != max_idx)
            rb(b, c);
    else
        while (b->top->index != max_idx)
            rrb(b, c);
}

void	sort_three(t_stack *a, t_counts *c)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(a))
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, c);
	else if (first > second && second > third)
	{
		sa(a, c);
		rra(a, c);
	}
	else if (first > second && second < third && first > third)
		ra(a, c);
	else if (first < second && second > third && first < third)
	{
		sa(a, c);
		ra(a, c);
	}
	else if (first < second && second > third && first > third)
		rra(a, c);
}

void	sort_five(t_stack *a, t_stack *b, t_counts *c)
{
	while (a->size > 3)
	{
		move_min_to_top_a(a, c);
		if (is_sorted(a))
			break ;
		pb(a, b, c);
	}
	sort_three(a, c);
	while (b->size)
		pa(a, b, c);
}
