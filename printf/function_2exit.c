/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_2exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:08:31 by rstrcic           #+#    #+#             */
/*   Updated: 2025/12/10 11:29:51 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_tunsigned_int(unsigned int nbr)
{
	int		i;
	char	*str;

	i = 0;
	if (nbr == 0)
		i += write(2, "0", 1);
	else
	{
		str = ft_unsigned_itoa(nbr);
		i = print_str(str);
		free(str);
	}
	return (i);
}

int	print_thex(unsigned int nbr, char format)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (format == 'x')
		str = ft_get_hex_str(nbr, "0123456789abcdef");
	else if (format == 'X')
		str = ft_get_hex_str(nbr, "0123456789ABCDEF");
	if (str != NULL)
	{
		i = print_tstr(str);
		free(str);
	}
	return (i);
}

int	print_tstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_thex_ptr(unsigned long int nbr)
{
	char	*str;
	int		len;

	if (nbr == 0)
		return (write(2, "(nil)", 5));
	str = ft_hex_ptr_itoa(nbr);
	if (!str)
		return (0);
	len = ft_tputstr(str);
	free(str);
	return (len);
}

int	get_tparam(va_list args, char format)
{
	int	print;

	print = 0;
	if (format == 'i' || format == 'd')
		print += print_tint(va_arg(args, int));
	else if (format == 'c')
		print += ft_tputchar(va_arg(args, int));
	else if (format == '%')
	{
		ft_tputchar('%');
		print += 1;
	}
	else if (format == 'p')
		print += print_thex_ptr(va_arg(args, unsigned long));
	else if (format == 'u')
		print += print_tunsigned_int(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print += print_thex(va_arg(args, unsigned int), format);
	else if (format == 's')
		print += print_tstr(va_arg(args, char *));
	return (print);
}
