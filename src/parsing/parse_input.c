#include "../../include/push_swap.h"

static int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static int	*convert_to_ints(char **args, int size)
{
	int	*values;
	int	i;
	int	error;

	values = ft_calloc(size, sizeof(int));
	if (!values)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!is_valid_number(args[i]))
		{
			free(values);
			return (NULL);
		}
		values[i] = ft_atoi_safe(args[i], &error);
		if (error)
		{
			free(values);
			return (NULL);
		}
		i++;
	}
	return (values);
}

static void	fill_stack_a(t_data *data, int *values, int size)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (i < size)
	{
		new = stack_new(values[i]);
		if (!new)
		{
			stack_clear(&data->stack_a);
			free(values);
			error_exit();
		}
		stack_add_back(&data->stack_a, new);
		i++;
	}
}

int	parse_arguments(int argc, char **argv, int start, t_data *data)
{
	char	**args;
	int		*values;

	if (argc < 2)
		return (0);
	args = split_all_args(argc, argv, start);
	if (!args)
		error_exit();
	data->size_a = count_args(args);
	values = convert_to_ints(args, data->size_a);
	if (!values)
	{
		free_split(args);
		error_exit();
	}
	if (has_duplicates(values, data->size_a))
	{
		free_split(args);
		free(values);
		error_exit();
	}
	fill_stack_a(data, values, data->size_a);
	free_split(args);
	free(values);
	return (1);
}