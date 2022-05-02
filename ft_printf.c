/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:16:33 by rrangwan          #+#    #+#             */
/*   Updated: 2022/01/28 13:05:13 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_n(int n)
{
	int	temp;

	temp = 0;
	if (n < 0)
	{
		temp++;
		write(1, "-", 1);
		n *= -1;
	}
	return (print_n2(n) + temp);
}

int	print_n2(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
	{
		ret += print_n2(n / 10);
		ret += print_n2(n % 10);
	}
	if (n < 10)
		ret += print_c(n + '0');
	return (ret);
}

int	ft_printer(char conv, va_list *va)
{
	int	ret;

	ret = 0;
	if (conv == 'c')
		ret += print_c(va_arg(*va, int));
	if (conv == '%')
		ret += write(1, "%", 1);
	if (conv == 'd' || conv == 'i')
		ret += print_n(va_arg(*va, int));
	if (conv == 'u')
		ret += print_n2(va_arg(*va, unsigned int));
	if (conv == 'x' || conv == 'X')
		ret += print_h(va_arg(*va, unsigned int), conv);
	if (conv == 'p')
	{
		ret += print_s("0x");
		ret += print_p(va_arg(*va, unsigned long int));
	}
	if (conv == 's')
		ret += print_s(va_arg(*va, char *));
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int			ret;
	int			i;
	va_list		va;

	ret = 0;
	i = 0;
	va_start(va, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			ret++;
		}
		if (format[i] == '%')
		{
			i++;
			ret += ft_printer(format[i], &va);
		}
		i++;
	}
	va_end(va);
	return (ret);
}
