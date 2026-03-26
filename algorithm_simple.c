#include "push_swap.h"

void	simple_sort(t_stack *a, t_stack *b)
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
			ra(a);
		pb(a, b);
	}
	while (b->size)
		pa(a, b);
}