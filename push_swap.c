#include "push_swap.h"

static void	init_counters(t_data *data)
{
	data->sa_count = 0;
	data->sb_count = 0;
	data->ss_count = 0;
	data->pa_count = 0;
	data->pb_count = 0;
	data->ra_count = 0;
	data->rb_count = 0;
	data->rr_count = 0;
	data->rra_count = 0;
	data->rrb_count = 0;
	data->rrr_count = 0;
}

static void	init_data(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->bench = 0;
	data->disorder = 0;
	data->strategy = ADAPTIVE;
	data->used_strategy = ADAPTIVE;
	data->total_ops = 0;
	init_counters(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		start;

	if (argc < 2)
		return (0);
	init_data(&data);
	start = parse_flags(argc, argv, &data);
	if (start >= argc)
		return (0);
	parse_arguments(argc, argv, start, &data);
	data.disorder = compute_disorder(data.stack_a);
	if (!is_sorted(data.stack_a))
		run_strategy(&data);
	if (data.bench)
		print_bench(&data);
	stack_clear(&data.stack_a);
	stack_clear(&data.stack_b);

	return (0);
}