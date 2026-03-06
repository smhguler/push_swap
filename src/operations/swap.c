#include "../../include/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_data *data)
{
	swap(&data->stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	swap(&data->stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	swap(&data->stack_a);
	swap(&data->stack_b);
	write(1, "ss\n", 3);
}
