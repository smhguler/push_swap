#include "../../include/push_swap.h"

static int	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

void	ra(t_data *data)
{
	if (rotate_stack(&data->stack_a))
		write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	if (rotate_stack(&data->stack_b))
		write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	int	a_rotated;
	int	b_rotated;

	a_rotated = rotate_stack(&data->stack_a);
	b_rotated = rotate_stack(&data->stack_b);
	if (a_rotated || b_rotated)
		write(1, "rr\n", 3);
}