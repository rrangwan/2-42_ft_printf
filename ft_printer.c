/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:16:41 by rrangwan          #+#    #+#             */
/*   Updated: 2022/01/28 13:06:11 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(unsigned long int n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += print_p(n / 16);
		ret += print_p(n % 16);
	}
	if (n < 16)
	{
		if (n < 10)
			ret += print_c(n + '0');
		else
			ret += print_c(n + ('a' - 10));
	}
	return (ret);
}

int	print_h(unsigned int n, char h)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += print_h(n / 16, h);
		ret += print_h(n % 16, h);
	}
	if (n < 16)
	{
		if (n < 10)
			ret += print_c(n + '0');
		else
		{
			if (h == 'x')
				ret += print_c(n + ('a' - 10));
			else
				ret += print_c(n + ('A' - 10));
		}
	}
	return (ret);
}

int	print_s(char	*s)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		ret++;
		i++;
	}
	return (ret);
}
