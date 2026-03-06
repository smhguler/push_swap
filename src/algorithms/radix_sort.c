#include "../../include/push_swap.h"

static void	index_stack(t_data *data)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = data->stack_a;
	while (current)
	{
		index = 0;
		compare = data->stack_a;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

void	radix_sort(t_data *data)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	if (data->size_a <= 1)
		return ;
	index_stack(data);
	max_bits = get_max_bits(data->size_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = data->size_a;
		while (j < size)
		{
			if (((data->stack_a->index >> i) & 1) == 0)
				pb(data);
			else
				ra(data);
			j++;
		}
		while (data->size_b > 0)
			pa(data);
		i++;
	}
}