#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
}   t_stack;

typedef struct s_data
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     size_a;
    int     size_b;
}   t_data;

int     parse_arguments(int argc, char **argv, t_data *data);
char    **split_all_args(int argc, char **argv);
int     is_valid_number(char *str);
int     ft_atoi_safe(char *str, int *error);
int     has_duplicates(int *arr, int size);

char    **ft_split(char const *s, char c);
long    ft_atol(const char *str);
int     ft_isdigit(int c);
size_t  ft_strlen(const char *s);
void    *ft_calloc(size_t count, size_t size);

t_stack *stack_new(int value);
void    stack_add_back(t_stack **stack, t_stack *new);
t_stack *stack_last(t_stack *stack);
int     stack_size(t_stack *stack);
void    stack_clear(t_stack **stack);
int     is_sorted(t_stack *stack);

void    error_exit(void);
void    free_split(char **split);
void    free_array(int *arr);

void    simple_sort(t_data *data);
void    radix_sort(t_data *data);

void    sa(t_data *data);
void    sb(t_data *data);
void    ss(t_data *data);
void    pa(t_data *data);
void    pb(t_data *data);
void    ra(t_data *data);
void    rb(t_data *data);
void    rr(t_data *data);
void    rra(t_data *data);
void    rrb(t_data *data);
void    rrr(t_data *data);

#endif