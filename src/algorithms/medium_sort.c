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
 
static void	sort_small(t_data *data)
{
	if (data->size_a <= 1 || is_sorted(data->stack_a))
		return ;
	if (data->size_a == 2)
	{
		sa(data);
		return ;
	}
	if (data->size_a == 3)
	{
		sort_three(data);
		return ;
	}
	while (data->size_a > 3)
		push_min_to_b(data);
	sort_three(data);
	while (data->stack_b)
		pa(data);
}
 
static void	push_chunks(t_data *data)
{
	int	chunk;
	int	chunk_end;
	int	pushed;

	index_medium(data);
	chunk = ft_sqrt(data->size_a);
	chunk_end = chunk;
	pushed = 0;
	while (data->size_a > 0)
	{
		if (data->stack_a->index <= chunk_end)
		{
			pb(data);
			pushed++;
			if (pushed % chunk == 0)
				chunk_end += chunk;
		}
		else
			ra(data);
	}
}
 
static void	push_back(t_data *data)
{
	int	max_pos;
	int	size;
 
	while (data->size_b > 0)
	{
		max_pos = find_max_pos(data->stack_b);
		size = data->size_b;
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(data);
		}
		else
		{
			while (max_pos++ < size)
				rrb(data);
		}
		pa(data);
	}
}
 
void	medium_sort(t_data *data)
{
	if (data->size_a <= 5)
	{
		sort_small(data);
		return ;
	}
	push_chunks(data);
	push_back(data);
}