#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*f;
	t_node	*s;

	if (!a || a->size < 2)
		return ;
	f = a->top;
	s = f->next;
	f->next = s->next;
	s->next = f;
	a->top = s;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_node	*f;
	t_node	*s;

	if (!b || b->size < 2)
		return ;
	f = b->top;
	s = f->next;
	f->next = s->next;
	s->next = f;
	b->top = s;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
