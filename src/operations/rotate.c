#include "../../include/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_data *data)
{
	rotate(&data->stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	rotate(&data->stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	rotate(&data->stack_a);
	rotate(&data->stack_b);
	write(1, "rr\n", 3);
}
