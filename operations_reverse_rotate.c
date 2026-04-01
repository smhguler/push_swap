#include "push_swap.h"

void	rra(t_stack *a, t_counts *c)
{
	t_node	*prev;
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	prev = NULL;
	last = a->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
	c->count_rra++;
	c->count_total++;
}

void	rrb(t_stack *b, t_counts *c)
{
	t_node	*prev;
	t_node	*last;

	if (!b || b->size < 2)
		return ;
	prev = NULL;
	last = b->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = b->top;
	b->top = last;
	write(1, "rrb\n", 4);
	c->count_rrb++;
	c->count_total++;
}

void	rrr(t_stack *a, t_stack *b, t_counts *c)
{
	rra(a,c);
	rrb(b,c);
	write(1, "rrr\n", 4);
	c->count_rrr++;
	c->count_total++;
}
