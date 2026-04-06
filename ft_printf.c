/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:00:36 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/06 16:57:15 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		summation;

	summation = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
			{
				va_end(args);
				return (-1);
			}
			summation += ft_format(args, *format);
		}
		else
			summation += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (summation);
}
