#include "../../include/push_swap.h"

void	run_strategy(t_data *data)
{
	if (data->strategy == SIMPLE)
	{
		data->used_strategy = SIMPLE;
		simple_sort(data);
	}
	else if (data->strategy == MEDIUM)
	{
		data->used_strategy = MEDIUM;
		medium_sort(data);
	}
	else if (data->strategy == COMPLEX)
	{
		data->used_strategy = COMPLEX;
		radix_sort(data);
	}
	else
		adaptive_sort(data);
}