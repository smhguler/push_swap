/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:19:16 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/07 18:26:43 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	complex_sort(t_stack *a, t_stack *b, t_counts *c)
{
	int i;
    int max_bits;
    int size;

    size = a->size;
    max_bits = get_max_bits(size);
    i = 0;
    if (size <= 5)
        sorting(a, b, c);
    else
    {
        while (i < max_bits)
        {
            size = a->size;
            while (size--)
                if (((a->top->index >> i) & 1) == 0)
                    pb(a, b, c);
                else
                    ra(a, c);
            while (b->size)
                pa(a, b, c);
            i++;
        }
    }
}
