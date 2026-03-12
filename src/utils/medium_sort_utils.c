#include "../../include/push_swap.h"
 
int	find_min_position(t_stack *stack)
{
	int	pos;
	int	min_pos;
	int	min;
 
	pos = 0;
	min_pos = 0;
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

int	find_max_pos(t_stack *stack)
{
	int	pos;
	int	max_pos;
	int	max;
 
	pos = 0;
	max_pos = 0;
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

void	index_medium(t_data *data)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		idx;
 
	cur = data->stack_a;
	while (cur)
	{
		idx = 0;
		cmp = data->stack_a;
		while (cmp)
		{
			if (cur->value > cmp->value)
				idx++;
			cmp = cmp->next;
		}
		cur->index = idx;
		cur = cur->next;
	}
}

int	ft_sqrt(int n)
{
	int	i;
 
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	push_min_to_b(t_data *data)
{
	int	min_pos;
	int	size;
 
	min_pos = find_min_position(data->stack_a);
	size = data->size_a;
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(data);
	}
	else
	{
		while (min_pos++ < size)
			rra(data);
	}
	pb(data);
}
