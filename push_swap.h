#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/* ================= STRUCT ================= */

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* ================= ERROR ================= */

void	error_exit(void);

/* ================= FREE ================= */

void	free_stack(t_stack *stack);

/* ================= PARSER ================= */

void	parse(t_stack *a, char **argv, int start);

/* ================= INDEX ================= */

void	assign_index(t_stack *a);

/* ================= ALGORITHMS ================= */

void	simple_sort(t_stack *a, t_stack *b);
void	medium_sort(t_stack *a, t_stack *b);
void	complex_sort(t_stack *a, t_stack *b);
void	adaptive_sort(t_stack *a, t_stack *b);

/* ================= OPERATIONS ================= */

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* ================= UTILS ================= */

double	compute_disorder(t_stack *a);

#endif