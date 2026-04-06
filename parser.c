/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:20:31 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/06 18:24:02 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(const char *str, int len)
{
	long	res;
	long	limit;
	int		s;
	int		i;

	res = 0;
	s = 1;
	i = 0;
	if (len <= 0)
		error_exit();
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			s = -1;
	if (i >= len)
		error_exit();
	limit = 2147483647LL + (s == -1);
	while (i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			error_exit();
		if (res > (limit - (str[i] - '0')) / 10)
			error_exit();
		res = res * 10 + (str[i++] - '0');
	}
	return ((int)(res * s));
}

static void	add_stack(t_stack *a, int value)
{
	t_node	*new;
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->value == value)
			error_exit();
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_node));
	if (!new)
		error_exit();
	new->value = value;
	new->next = NULL;
	if (!a->top)
		a->top = new;
	else
	{
		tmp = a->top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	a->size++;
}

static void	process_arg(t_stack *a, char *arg)
{
	int		len;
	char	*start;
	int		has_token;

	has_token = 0;
	while (*arg)
	{
		while (*arg && (*arg == ' ' || (*arg >= 9 && *arg <= 13)))
			arg++;
		if (!*arg)
			break ;
		has_token = 1;
		start = arg;
		len = 0;
		while (arg[len] && !(arg[len] == ' ' || (arg[len] >= 9
					&& arg[len] <= 13)))
			len++;
		add_stack(a, ft_atoi(start, len));
		arg += len;
	}
	if (!has_token)
		error_exit();
}

void	parse(t_stack *a, char **argv, int start)
{
	int	i;

	i = start;
	while (argv[i])
	{
		process_arg(a, argv[i]);
		i++;
	}
}
