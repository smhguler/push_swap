#include "../../include/push_swap.h"

int	ft_atoi_safe(char *str, int *error)
{
	long	result;

	*error = 0;
	result = ft_atol(str);
	if (result > 2147483647 || result < -2147483648)
	{
		*error = 1;
		return (0);
	}
	return ((int)result);
}
