#include "push_swap.h"

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
