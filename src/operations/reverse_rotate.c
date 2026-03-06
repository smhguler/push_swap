#include "../../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
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
}

void	rra(t_data *data)
{
	reverse_rotate(&data->stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_data *data)
{
	reverse_rotate(&data->stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	reverse_rotate(&data->stack_a);
	reverse_rotate(&data->stack_b);
	write(1, "rrr\n", 4);
}
