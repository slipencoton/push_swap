/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:47:49 by rstrcic           #+#    #+#             */
/*   Updated: 2025/12/10 11:29:14 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_tputchar(int c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, string);
	i = 0;
	len = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			len += get_param(args, string[i]);
		}
		else
			len += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_tprintf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, string);
	i = 0;
	len = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			len += get_tparam(args, string[i]);
		}
		else
			len += ft_tputchar(string[i]);
		i++;
	}
	va_end(args);
	return (len);
}
