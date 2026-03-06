#include "../include/push_swap.h"

static void	init_data(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	init_data(&data);
	parse_arguments(argc, argv, &data);
	if (is_sorted(data.stack_a))
	{
		radix_sort(&data);
		stack_clear(&data.stack_a);
		return (0);
	}
	stack_clear(&data.stack_a);
	stack_clear(&data.stack_b);
	return (0);
}
