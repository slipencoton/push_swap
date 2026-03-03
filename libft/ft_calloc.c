/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:41:33 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/10 08:47:18 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*buff;
	size_t			i;

	i = 0;
	if (nmemb <= 0 || size <= 0)
		return (malloc(0));
	if (nmemb > 2147483647 / size)
		return (NULL);
	buff = malloc(nmemb * size);
	if (!buff)
		return (NULL);
	while (i < nmemb * size)
	{
		buff[i] = 0;
		i++;
	}
	return (buff);
}
/*
int main(void)
{
	char *buff = NULL;
	buff = ft_calloc(__SIZE_MAX__, __SIZE_MAX__);
	printf("%lu", sizeof(buff));
	return (0);
}*/