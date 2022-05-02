/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:16:15 by rrangwan          #+#    #+#             */
/*   Updated: 2022/01/28 13:06:43 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	print_c(char c);
int	ft_printer(char conv, va_list *va);
int	ft_printf(const char *format, ...);
int	print_p(unsigned long int n);
int	print_n(int n);
int	print_n2(unsigned int n);
int	print_h(unsigned int n, char h);
int	print_s(char	*s);
#endif
