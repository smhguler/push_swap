#include "push_swap.h"

void	adaptive_sort(t_stack *a, t_stack *b)
{
	double	d;

	d = compute_disorder(a);
	if (d < 0.2)
		simple_sort(a, b);
	else if (d < 0.5)
		medium_sort(a, b);
	else
		complex_sort(a, b);
}
