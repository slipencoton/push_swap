/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrcic <rstrcic@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:43:47 by rstrcic           #+#    #+#             */
/*   Updated: 2025/11/19 09:31:11 by rstrcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_ptr_len(unsigned long int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

char	*ft_hex_ptr_itoa(unsigned long int n)
{
	const char	*hex;
	char		*str;
	int			len;

	hex = "0123456789abcdef";
	len = ft_hex_ptr_len(n);
	str = (char *)malloc(sizeof(char) * (len + 3));
	if (!str)
		return (NULL);
	str[len + 2] = '\0';
	while (len > 0)
	{
		str[len + 1] = hex[n % 16];
		n = n / 16;
		len--;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

int	print_hex_ptr(unsigned long int nbr)
{
	char	*str;
	int		len;

	if (nbr == 0)
		return (write(1, "(nil)", 5));
	str = ft_hex_ptr_itoa(nbr);
	if (!str)
		return (0);
	len = ft_putstr(str);
	free(str);
	return (len);
}
