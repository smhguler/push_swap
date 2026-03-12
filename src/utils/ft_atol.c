long	ft_atol(const char *str)
{
	int		sign;
	long	result;
	int		i;
	int		digits;

	i = 0;
	sign = 1;
	result = 0;
	digits = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		digits++;
		if (digits > 18)
			return (result * sign);
		i++;
	}
	return (result * sign);
}