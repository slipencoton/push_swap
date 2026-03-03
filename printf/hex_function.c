/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrcic <rstrcic@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:11:17 by rstrcic           #+#    #+#             */
/*   Updated: 2025/11/19 10:06:18 by rstrcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

char	*ft_get_hex_str(unsigned int n, char *base)
{
	unsigned int	nbr;
	int				len;
	char			*alpha;

	nbr = n;
	len = ft_hex_len(n);
	alpha = malloc(sizeof(char) * (len + 1));
	if (alpha == NULL)
		return (NULL);
	alpha[len] = '\0';
	if (n == 0)
		alpha[0] = '0';
	while (nbr != 0)
	{
		len--;
		alpha[len] = base[nbr % 16];
		nbr /= 16;
	}
	return (alpha);
}

int	print_hex(unsigned int nbr, char format)
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
		i = print_str(str);
		free(str);
	}
	return (i);
}
