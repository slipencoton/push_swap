/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_2exit2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:13:08 by rstrcic           #+#    #+#             */
/*   Updated: 2025/12/10 11:22:04 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tputstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_tputchar(str[i]);
		i++;
	}
	return (i);
}

int	print_tint(int nbr)
{
	int		i;
	char	*str;

	str = ft_itoa(nbr);
	i = print_tstr(str);
	free(str);
	return (i);
}
