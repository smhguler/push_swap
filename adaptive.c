/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:19:12 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/07 18:26:38 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack *a, t_stack *b, t_counts *c)
{
	double	d;

	d = compute_disorder(a);
	if (d < 0.2)
		simple_sort(a, b, c);
	else if (d < 0.5)
		medium_sort(a, b, c);
	else
		complex_sort(a, b, c);
}
