#include "../../include/push_swap.h"

static int	is_strategy_flag(char *arg, t_data *data)
{
	if (!ft_strncmp(arg, "--simple", 9))
		data->strategy = SIMPLE;
	else if (!ft_strncmp(arg, "--medium", 9))
		data->strategy = MEDIUM;
	else if (!ft_strncmp(arg, "--complex", 10))
		data->strategy = COMPLEX;
	else if (!ft_strncmp(arg, "--adaptive", 11))
		data->strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

int	parse_flags(int argc, char **argv, t_data *data)
{
	int	i;
	int	strategy_seen;

	i = 1;
	strategy_seen = 0;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
			data->bench = 1;
		else if (is_strategy_flag(argv[i], data))
		{
			if (strategy_seen)
				error_exit();
			strategy_seen = 1;
		}
		else
			break ;
		i++;
	}
	return (i);
}