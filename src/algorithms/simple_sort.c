#include "../../include/push_swap.h"

static int find_min_pos(t_stack *stack)
{
    int min;
    int minpos;
    int i;
    
    min=stack->value;
    minpos=0;
    i=0;
    while (stack)
    {
        if(stack->value<min)
        {
            min=stack->value;
            minpos=i;
        }
        stack = stack->next;
        i++;
        
    }
    return(minpos);
}


static void push_min(t_data *data)
{
    int pos,size;
    size=data ->size_a;
    pos =find_min_pos(data->stack_a);
    if(pos<=size/2)
    {
        while (pos)
        {
            ra(data);
            pos--;
        }       
    }
    else
    {
        while(pos<size)
        {
            rra(data);
            pos++;
        }
    }
    pb(data);
}

 void simple_sort(t_data *data)
 {
    while(data->size_a>0&&!is_sorted(data->stack_a))
    {
        push_min(data);
    }
    while(data->size_b>0)
    {
        pa(data);
    }
 }