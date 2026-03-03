/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:47:53 by rstrcic           #+#    #+#             */
/*   Updated: 2025/12/10 14:18:39 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	unsigned int	nbr;
	int				len;
	char			*alpha;

	nbr = n;
	len = ft_unsigned_len(n);
	alpha = NULL;
	alpha = malloc(sizeof(char) * len + 1);
	if (alpha == NULL)
		return (NULL);
	alpha[len--] = '\0';
	while (len >= 0)
	{
		alpha[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (alpha);
}

int	print_unsigned_int(unsigned int nbr)
{
	int		i;
	char	*str;

	i = 0;
	if (nbr == 0)
		i += write(1, "0", 1);
	else
	{
		str = ft_unsigned_itoa(nbr);
		i = print_str(str);
		free(str);
	}
	return (i);
}

int	get_param(va_list args, char format)
{
	int	print;

	print = 0;
	if (format == 'i' || format == 'd')
		print += print_int(va_arg(args, int));
	else if (format == 'c')
		print += ft_putchar(va_arg(args, int));
	else if (format == '%')
	{
		ft_putchar('%');
		print += 1;
	}
	else if (format == 'p')
		print += print_hex_ptr(va_arg(args, unsigned long));
	else if (format == 'u')
		print += print_unsigned_int(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print += print_hex(va_arg(args, unsigned int), format);
	else if (format == 's')
		print += print_str(va_arg(args, char *));
	return (print);
}
