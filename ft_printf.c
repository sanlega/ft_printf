/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:58:40 by slegaris          #+#    #+#             */
/*   Updated: 2023/05/23 03:07:43 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int ft_charcheck(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_unsg(va_arg(args, int)));
	if (c == 'x')
		return (ft_putnbrhex_minus(va_arg(args, int)));
	if (c == 'X')
		return (ft_putnbrhex_mayus(va_arg(args, int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_formatcheck(char *str, va_list variables)
{
	int i;
	int length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%' && str[i - 1] != '%')
		{
			length += ft_putchar(str[i]);
			i++;
		}
		if (str[i] == '%')
		{
			length += ft_charcheck(str[i + 1], variables);
			i += 2;
		}
	}
	return (length);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		length;

	va_start(args, format);
	length = ft_formatcheck((char *)format, args);
	va_end(args);
	return (length);
}

// int main()
// {
//     // Printing a character
//     char c = 'A';
//     ft_printf("The character is: %c\n", c);
//
//     // // Printing a string
//     // char *str = "Hello, world!";
//     // ft_printf("The string is: %s\n", str);
//     //
//     // // Printing a pointer
//     // int *p = &c;
//     // ft_printf("The pointer is: %p\n", p);
//     //
//     // // Printing a decimal number
//     // int d = 1234;
//     // ft_printf("The decimal number is: %d\n", d);
//     //
//     // // Printing an integer
//     // int i = 5678;
//     // ft_printf("The integer is: %i\n", i);
//     //
//     // // Printing an unsigned number
//     // unsigned int u = 1234567890;
//     // ft_printf("The unsigned number is: %u\n", u);
//     //
//     // // Printing a hexadecimal number (lowercase)
//     // int x = 0x123;
//     // ft_printf("The hexadecimal number (lowercase) is: %x\n", x);
//     //
//     // // Printing a hexadecimal number (uppercase)
//     // int X = 0xABC;
//     // ft_printf("The hexadecimal number (uppercase) is: %X\n", X);
//     //
//     // // Printing a percentage symbol
//     // ft_printf("The percentage symbol is: %%\n");
//
//     return 0;
// }