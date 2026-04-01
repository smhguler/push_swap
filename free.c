#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	free(stack);
}

void	reset_counts(t_counts *c)
{
	c->count_total = 0;
	c->count_sa = 0;
	c->count_sb = 0;
	c->count_ss = 0;
	c->count_pa = 0;
	c->count_pb = 0;
	c->count_ra = 0;
	c->count_rb = 0;
	c->count_rr = 0;
	c->count_rra = 0;
	c->count_rrb = 0;
	c->count_rrr = 0;
}