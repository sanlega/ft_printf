/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex_mayus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:58:37 by slegaris          #+#    #+#             */
/*   Updated: 2023/05/23 03:45:11 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	nb;
	int		count;

	len = ft_strlen(base);
	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb < len)
	{
		count += ft_putchar(base[nb]);
	}
	if (nb >= len)
	{
		count += ft_putnbr_base(nb / len, base);
		count += ft_putnbr_base(nb % len, base);
	}
	return (count);
}

int	ft_putnbrhex_mayus(int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	count = ft_putnbr_base(n, base);
	return (count);
}
