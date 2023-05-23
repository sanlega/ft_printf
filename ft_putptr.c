/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:27:32 by slegaris          #+#    #+#             */
/*   Updated: 2023/05/23 02:45:53 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>

// int	ft_putptr_base(uintptr_t nbr, char *base)
// {
// 	int		len;
// 	long	nb;
// 	int count;
//
// 	len = ft_strlen(base);
// 	nb = nbr;
// 	count = 0;
// 	count += ft_putchar('0');
// 	count += ft_putchar('x');
// 	if (nb < len)
// 	{
// 		count += ft_putchar(base[nb]);
// 	}
// 	if (nb >= len)
// 	{
// 		count += ft_putptr_base(nb / len, base);
// 		count += ft_putptr_base(nb % len, base);
// 	}
// 	return (count);
// }


int ft_putptr_base(uintptr_t nbr, char *base)
{
    int len;
    int count = 0;

    len = ft_strlen(base);
    if (nbr >= (uintptr_t)len)
    {
        count += ft_putptr_base(nbr / len, base);
        count += ft_putptr_base(nbr % len, base);
    }
    else
    {
        count += ft_putchar(base[nbr]);
    }
    return count;
}

int ft_putptr(void *ptr)
{
    int count;
    char *base;

    base = "0123456789abcdef";
    count = ft_putchar('0');
    count += ft_putchar('x');
    count += ft_putptr_base((uintptr_t)ptr, base);
    return count;
}
// int main()
// {
//     int num = 12345;
//     printf("\nCustom function char count: %d\n", ft_putptr(&num));
//     printf("Original printf: %p\n", &num);
//     return (0);
// }
