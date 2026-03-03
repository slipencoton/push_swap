/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:15:29 by qbourine          #+#    #+#             */
/*   Updated: 2025/12/09 15:00:38 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_atoi(const char *nptr)
{
	int		i;
	int		s;
	size_t	r;

	i = 0;
	r = 0;
	s = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		s = s * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = (r * 10) + nptr[i] - 48;
		i++;
	}
	return (r * s);
}

// int	main(void)
// {
// 	char	nb[] = "214748364748385";
// 	printf("%zu", ft_atoi(nb));
// 	return (0);
// }
