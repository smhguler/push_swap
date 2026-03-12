#include "../../include/push_swap.h"

static int	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	sa(t_data *data)
{
	if (swap_stack(&data->stack_a))
	{
		write(1, "sa\n", 3);
		count_op(data, "sa");
	}
}

void	sb(t_data *data)
{
	if (swap_stack(&data->stack_b))
	{
		write(1, "sb\n", 3);
		count_op(data, "sb");
	}
}

void	ss(t_data *data)
{
	int	a_swapped;
	int	b_swapped;

	a_swapped = swap_stack(&data->stack_a);
	b_swapped = swap_stack(&data->stack_b);
	if (a_swapped || b_swapped)
	{
		write(1, "ss\n", 3);
		count_op(data, "ss");
	}
}