#include "../../include/push_swap.h"

static void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->stack_a->value;
	b = data->stack_a->next->value;
	c = data->stack_a->next->next->value;
	if (a > b && b < c && a < c)
		sa(data);
	else if (a > b && b > c)
	{
		sa(data);
		rra(data);
	}
	else if (a > b && b < c && a > c)
		ra(data);
	else if (a < b && b > c && a < c)
	{
		sa(data);
		ra(data);
	}
	else if (a < b && b > c && a > c)
		rra(data);
}

static void	push_min_to_b(t_data *data)
{
	int	min_pos;
	int	size;

	min_pos = find_min_position(data->stack_a);
	size = stack_size(data->stack_a);
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			ra(data);
	else
		while (min_pos++ < size)
			rra(data);
	pb(data);
}

void	medium_sort(t_data *data)
{
	int	size;

	size = stack_size(data->stack_a);
	if (size == 2 && !is_sorted(data->stack_a))
		sa(data);
	else if (size == 3)
		sort_three(data);
	else if (size <= 5)
	{
		while (stack_size(data->stack_a) > 3)
			push_min_to_b(data);
		sort_three(data);
		while (data->stack_b)
			pa(data);
	}
	else
		radix_sort(data);
}