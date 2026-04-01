#include "push_swap.h"

void	simple_sort(t_stack *a, t_stack *b, t_counts *c)
{
	int		min;
	t_node	*tmp;

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
