/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:20:39 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/07 18:28:03 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
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

typedef struct s_main_vars
{
	t_stack			*a;
	t_stack			*b;
	t_counts		c;
	int				i;
	int				mode;
	int				bench;
	double			disorder;
}					t_main_vars;

void				error_exit(void);

void				free_stack(t_stack *stack);
void				reset_counts(t_counts *c);

void				parse(t_stack *a, char **argv, int start);

void				assign_index(t_stack *a);

void				simple_sort(t_stack *a, t_stack *b, t_counts *c);
void				medium_sort(t_stack *a, t_stack *b, t_counts *c);
void				complex_sort(t_stack *a, t_stack *b, t_counts *c);
void				sort_three(t_stack *a, t_counts *c);
void				sort_five(t_stack *a, t_stack *b, t_counts *c);
void				sorting(t_stack *a, t_stack *b, t_counts *c);
void				move_min_to_top_a(t_stack *a, t_counts *c);
void				move_max_to_top_b(t_stack *b, t_counts *c);

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

double				compute_disorder(t_stack *a);
void				adaptive_sort(t_stack *a, t_stack *b, t_counts *c);
void				print_benchmark(t_counts *c, int bench_mode, int mode,
						double disorder);
int					ft_printf(const char *format, ...);
int					ft_putchar(char c);
int					ft_putstr(char *s);
int					ft_putnbr(long n);
int					ft_putfloat(double n, int precision);
int					ft_format(va_list args, char format);
int					ft_strcmp(char *s1, char *s2);
int					strategy_selector(char *arg);
int					is_sorted(t_stack *a);
t_stack				*init_stack(void);
void				count_only(t_counts *c);

#endif