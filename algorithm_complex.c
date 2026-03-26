#include "push_swap.h"

void	complex_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	max_bits;
	int	size;

	size = a->size;
	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		size = a->size;
		while (size--)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (b->size)
			pa(a, b);
		i++;
	}
}