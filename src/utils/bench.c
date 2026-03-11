#include "../../include/push_swap.h"

char	*strategy_name(t_data *data)
{
	if (data->used_strategy == SIMPLE)
		return ("Simple");
	if (data->used_strategy == MEDIUM)
		return ("Medium");
	if (data->used_strategy == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*strategy_complexity(t_data *data)
{
	if (data->used_strategy == SIMPLE)
		return ("O(n^2)");
	if (data->used_strategy == MEDIUM)
		return ("O(n*sqrt(n))");
	if (data->used_strategy == COMPLEX)
		return ("O(n log n)");
	return ("Adaptive");
}

static void	print_percent(double value)
{
	int	whole;
	int	frac;

	whole = (int)value;
	frac = (int)((value - whole) * 100 + 0.5);
	if (frac == 100)
	{
		whole++;
		frac = 0;
	}
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (frac < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(frac, 2);
}

void	print_bench(t_data *data)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(data->disorder * 100.0);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(data), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(strategy_complexity(data), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data->total_ops, 2);
	ft_putstr_fd("\n", 2);
	print_bench_ops(data);
}