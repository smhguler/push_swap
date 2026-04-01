#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ================= STRUCT ================= */

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct s_counts
{
	int				count_total;
	int				count_sa;
	int				count_sb;
	int				count_ss;
	int				count_pa;
	int				count_pb;
	int				count_ra;
	int				count_rb;
	int				count_rr;
	int				count_rra;
	int				count_rrb;
	int				count_rrr;
}					t_counts;

/* ================= ERROR ================= */

void				error_exit(void);

/* ================= FREE ================= */

void				free_stack(t_stack *stack);
void				reset_counts(t_counts *c);

/* ================= PARSER ================= */

void				parse(t_stack *a, char **argv, int start);

/* ================= INDEX ================= */

void				assign_index(t_stack *a);

/* ================= ALGORITHMS ================= */

void				simple_sort(t_stack *a, t_stack *b, t_counts *c);
void				medium_sort(t_stack *a, t_stack *b, t_counts *c);
void				complex_sort(t_stack *a, t_stack *b, t_counts *c);

/* ================= OPERATIONS ================= */

void				sa(t_stack *a, t_counts *c);
void				sb(t_stack *b, t_counts *c);
void				ss(t_stack *a, t_stack *b, t_counts *c);

void				pa(t_stack *a, t_stack *b, t_counts *c);
void				pb(t_stack *a, t_stack *b, t_counts *c);

void				ra(t_stack *a, t_counts *c);
void				rb(t_stack *b, t_counts *c);
void				rr(t_stack *a, t_stack *b, t_counts *c);

void				rra(t_stack *a, t_counts *c);
void				rrb(t_stack *b, t_counts *c);
void				rrr(t_stack *a, t_stack *b, t_counts *c);

/* ================= UTILS ================= */

double				compute_disorder(t_stack *a);
void				adaptive_sort(t_stack *a, t_stack *b, t_counts *c);
void				print_benchmark(t_counts *c, int bench_mode, int mode,
						double disorder);
#endif