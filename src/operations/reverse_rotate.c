#include "../../include/push_swap.h"

static int	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_data *data)
{
	if (reverse_rotate_stack(&data->stack_a))
	{	
		write(1, "rra\n", 4);
		count_op(data, "rra");
	}
}

void	rrb(t_data *data)
{
	if (reverse_rotate_stack(&data->stack_b))
	{
		write(1, "rrb\n", 4);
		count_op(data, "rrb");
	}
}

void	rrr(t_data *data)
{
	int	a_rotated;
	int	b_rotated;

	a_rotated = reverse_rotate_stack(&data->stack_a);
	b_rotated = reverse_rotate_stack(&data->stack_b);
	if (a_rotated || b_rotated)
	{
		write(1, "rrr\n", 4);
		count_op(data, "rrr");
	}
}