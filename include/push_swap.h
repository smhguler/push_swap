#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_data
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			size_a;
	int			size_b;
	int			bench;
	double		disorder;
	t_strategy	strategy;
	t_strategy	used_strategy;
	int			total_ops;
	int			sa_count;
	int			sb_count;
	int			ss_count;
	int			pa_count;
	int			pb_count;
	int			ra_count;
	int			rb_count;
	int			rr_count;
	int			rra_count;
	int			rrb_count;
	int			rrr_count;
}	t_data;

/* parsing */

int		parse_arguments(int argc, char **argv, int start, t_data *data);
char	**split_all_args(int argc, char **argv, int start);
int		parse_flags(int argc, char **argv, t_data *data);
int		is_valid_number(char *str);
int		ft_atoi_safe(char *str, int *error);
int		has_duplicates(int *arr, int size);

/* utils */

char	**ft_split(char const *s, char c);
long	ft_atol(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
char	*strategy_name(t_data *data);
char	*strategy_complexity(t_data *data);
void	print_bench_ops(t_data *data);

/* stack */

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);
void	stack_clear(t_stack **stack);
int		is_sorted(t_stack *stack);

/* error */

void	error_exit(void);
void	free_split(char **split);

/* algorithms */

void	simple_sort(t_data *data);
void	medium_sort(t_data *data);
void	radix_sort(t_data *data);
void	adaptive_sort(t_data *data);
void	run_strategy(t_data *data);
int		find_min_position(t_stack *stack);
double	compute_disorder(t_stack *stack);

/* bench */

void	print_bench(t_data *data);
void	count_op(t_data *data, char *op);

/* operations */

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

#endif