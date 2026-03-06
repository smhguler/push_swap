#include "../../include/push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_data *data)
{
	push(&data->stack_a, &data->stack_b);
	data->size_a++;
	data->size_b--;
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	push(&data->stack_b, &data->stack_a);
	data->size_b++;
	data->size_a--;
	write(1, "pb\n", 3);
}
