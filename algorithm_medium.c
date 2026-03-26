#include "push_swap.h"

void	medium_sort(t_stack *a, t_stack *b)
{
	int	chunk;
	int	i;

	if (a->size <= 100)
		chunk = 15;
	else
		chunk = 35;
	i = 0;
	while (a->size)
	{
		if (a->top->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->top->index <= i + chunk)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	while (b->size)
		pa(a, b);
}