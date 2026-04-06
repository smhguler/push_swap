/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaktas<vaktas@student.42istanbul.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:12:42 by vaktas            #+#    #+#             */
/*   Updated: 2026/04/06 18:24:48 by vaktas           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	return (write(2, &c, 1));
}

int	ft_putstr(char *s)
{
	int	total;
	int	check;

	total = 0;
	check = 0;
	if (!s)
		return (write(2, "(null)", 6));
	while (s[total])
	{
		check = ft_putchar(s[total]);
		if (check == -1)
			return (-1);
		total++;
	}
	return (total);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putfloat(double n, int precision)
{
	int		count;
	long	int_part;
	double	dec_part;
	int		digit;

	count = 0;
	int_part = (long)n;
	count += ft_putnbr(int_part);
	count += ft_putchar('.');
	dec_part = n - (double)int_part;
	if (dec_part < 0)
		dec_part = -dec_part;
	while (precision--)
	{
		dec_part *= 10;
		digit = (int)dec_part;
		count += ft_putchar(digit + '0');
		dec_part -= digit;
	}
	return (count);
}
