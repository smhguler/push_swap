#include "../../include/push_swap.h"

void	print_bench_ops(t_data *data)
{
	ft_putstr_fd("[bench] sa:", 2);
	ft_putnbr_fd(data->sa_count, 2);
	ft_putstr_fd(" sb:", 2);
	ft_putnbr_fd(data->sb_count, 2);
	ft_putstr_fd(" ss:", 2);
	ft_putnbr_fd(data->ss_count, 2);
	ft_putstr_fd(" pa:", 2);
	ft_putnbr_fd(data->pa_count, 2);
	ft_putstr_fd(" pb:", 2);
	ft_putnbr_fd(data->pb_count, 2);
	ft_putstr_fd(" ra:", 2);
	ft_putnbr_fd(data->ra_count, 2);
	ft_putstr_fd(" rb:", 2);
	ft_putnbr_fd(data->rb_count, 2);
	ft_putstr_fd(" rr:", 2);
	ft_putnbr_fd(data->rr_count, 2);
	ft_putstr_fd(" rra:", 2);
	ft_putnbr_fd(data->rra_count, 2);
	ft_putstr_fd(" rrb:", 2);
	ft_putnbr_fd(data->rrb_count, 2);
	ft_putstr_fd(" rrr:", 2);
	ft_putnbr_fd(data->rrr_count, 2);
	ft_putstr_fd("\n", 2);
}