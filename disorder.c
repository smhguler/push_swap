#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		m;
	int		t;

	m = 0;
	t = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			t++;
			if (i->value > j->value)
				m++;
			j = j->next;
		}
		i = i->next;
	}
	if (t == 0)
		return (0);
	return (((double)m / t));
}
