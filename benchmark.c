#include "push_swap.h"

static const char	*strategy_name(int mode, double disorder)
{
	if (mode == 0)
		return ("Simple / O(n^2)");
	if (mode == 1)
		return ("Medium / O(n√n)");
	if (mode == 2)
		return ("Complex / O(n log n)");
	if (mode == 3)
	{
		if (disorder < 0.2)
			return ("Adaptive / O(n^2)");
		else if (disorder < 0.5)
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(nlogn)");
	}
	return ("Strategy Not Found");
}

void	print_benchmark(t_counts *c, int bench_mode, int mode,
		double disorder)
{
	int	count_total;

	if (bench_mode)
	{
		count_total = c->count_sa + c->count_sb + c->count_ss + c->count_pa
			+ c->count_pb + c->count_ra + c->count_rb + c->count_rr
			+ c->count_rra + c->count_rrb + c->count_rrr;
		fprintf(stderr, "[bench] Disorder: %.2f%%\n", (disorder * 100));
		fprintf(stderr, "[bench] Strategy: %s\n", strategy_name(mode, disorder));
		fprintf(stderr, "[bench] Total Operations: %d\n", count_total);
		fprintf(stderr, "[bench] sa=%d sb=%d ss=%d pa=%d pb=%d\n", c->count_sa,
			c->count_sb, c->count_ss, c->count_pa, c->count_pb);
		fprintf(stderr, "[bench] ra=%d rb=%d rr=%d rra=%d rrb=%d rrr=%d\n",
			c->count_ra, c->count_rb, c->count_rr, c->count_rra, c->count_rrb,
			c->count_rrr);
	}
}
