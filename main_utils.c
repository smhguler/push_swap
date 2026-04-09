/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:19:00 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/09 12:29:53 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	strategy_selector(char *arg)
{
	if (!arg)
		return (4);
	if (ft_strcmp(arg, "--simple") == 0)
		return (0);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (2);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (3);
	return (4);
}

int	is_sorted(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*init_stack(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		error_exit();
	s->top = NULL;
	s->size = 0;
	return (s);
}

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
