#include "../../include/push_swap.h"

static void	free_result_until(char **result, int count)
{
	while (count > 0)
	{
		count--;
		free(result[count]);
	}
	free(result);
}

static int	count_split_words(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

static int	count_total_args(int argc, char **argv, int start)
	char	**temp;
	int		total;
	int		i;

	total = 0;
	i = start;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			return (-1);
		total += count_split_words(temp);
		free_split(temp);
		i++;
	}
	return (total);
}

static int	copy_split_args(char **result, char **temp, int *k)
{
	int	j;
	
	j = 0;
	while (temp[j])
	{
		result[*k] = temp[j];
		(*k)++;
		j++;
	}
	free(temp);
	return (1);
}

char  **split_all_args(int argc, char **argv, int start)
{
	char	**result;
	char	**temp;
	int		total;
	int		i;
	int		k;

	total = count_total_args(argc, argv, start);
	if (total <= 0)
		return (NULL);
	result = ft_calloc(total + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = start;
	k = 0;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
		{
			free_result_until(result, k);
			return (NULL);
		}
		copy_split_args(result, temp, &k);
		i++;
	}
	result[k] = NULL;
	return (result);
}