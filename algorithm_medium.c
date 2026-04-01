#include "push_swap.h"

static int	find_max_pos(t_stack *b)
{
	int		max;
	int		pos;
	int		i;
	t_node	*tmp;

	max = b->top->index;
	pos = 0;
	i = 0;
	tmp = b->top;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void move_max_to_top(t_stack *b, t_counts *c)
{
	int	pos;

	pos = find_max_pos(b);
	if (pos <= b->size / 2)
	{
		while (pos--)
			rb(b, c);
	}
	else
	{
		pos = b->size - pos;
		while (pos--)
			rrb(b, c);
	}
}

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
		move_max_to_top(b, c);
		pa(a, b, c);
	}
}
