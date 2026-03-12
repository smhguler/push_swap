#include "../../include/push_swap.h"

void	adaptive_sort(t_data *data)
{
	if (data->disorder < 0.2)
	{
		data->used_strategy = SIMPLE;
		simple_sort(data);
	}
	else if (data->disorder < 0.5)
	{
		data->used_strategy = MEDIUM;
		medium_sort(data);
	}
	else
	{
		data->used_strategy = COMPLEX;
		radix_sort(data);
	}
}