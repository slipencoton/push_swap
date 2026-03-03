/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:53:59 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/10 08:45:45 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	size_t	i;
	char	*a;

	a = (char *) malloc(ft_strlen(src) + 1);
	if (!a)
		return (NULL);
	i = 0;
	while (src[i])
	{
		a[i] = src[i];
		i++;
	}
	a[i] = 0;
	return (a);
}
/*
int	main(void)
{
	char *c;

	c = ft_strdup("hello");
	printf("%s", c);
	return (0);
}*/