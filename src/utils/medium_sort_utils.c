#include "../../include/push_swap.h"

int	find_min_position(t_stack *stack)
{
	int	pos;
	int	min_pos;
	int	min;

	pos = 0;
	min_pos = 0;
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}