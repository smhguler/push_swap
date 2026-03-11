#include "../../include/push_swap.h"

void	count_op(t_data *data, char *op)
{
	data->total_ops++;
	if (!ft_strncmp(op, "sa", 3))
		data->sa_count++;
	else if (!ft_strncmp(op, "sb", 3))
		data->sb_count++;
	else if (!ft_strncmp(op, "ss", 3))
		data->ss_count++;
	else if (!ft_strncmp(op, "pa", 3))
		data->pa_count++;
	else if (!ft_strncmp(op, "pb", 3))
		data->pb_count++;
	else if (!ft_strncmp(op, "ra", 3))
		data->ra_count++;
	else if (!ft_strncmp(op, "rb", 3))
		data->rb_count++;
	else if (!ft_strncmp(op, "rrr", 4))
		data->rrr_count++;
	else if (!ft_strncmp(op, "rra", 4))
		data->rra_count++;
	else if (!ft_strncmp(op, "rrb", 4))
		data->rrb_count++;
	else if (!ft_strncmp(op, "rr", 3))
		data->rr_count++;
}