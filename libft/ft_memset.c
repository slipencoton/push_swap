/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:18:47 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/05 15:23:05 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = (char *) s;
	while (i < n)
	{
		cpy[i] = c;
		i++;
	}
	return (s);
}

/*
int main(void)
{
	char src[12];
	char *result = ft_memset(src, 86, 4);
	printf("%s", result);
	
	return (0);
	
}*/