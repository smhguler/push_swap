#include "../../include/push_swap.h"

static int	count_total_args(int argc, char **argv)
{
	char	**temp;
	int		total;
	int		i;
	int		j;

	total = 0;
	i = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
		{
			total++;
			j++;
		}
		free_split(temp);
		i++;
	}
	return (total);
}

static void	copy_split_args(char **result, char **temp, int *k)
{
	int	j;

	j = 0;
	while (temp[j])
	{
		result[*k] = temp[j];
		(*k)++;
		j++;
	}
}

char	**split_all_args(int argc, char **argv)
{
	char	**result;
	char	**temp;
	int		total;
	int		i;
	int		k;

	total = count_total_args(argc, argv);
	result = ft_calloc(total + 1, sizeof(char *));
	if (!result)
		return (NULL);
	k = 0;
	i = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		copy_split_args(result, temp, &k);
		free(temp);
		i++;
	}
	result[k] = NULL;
	return (result);
}
