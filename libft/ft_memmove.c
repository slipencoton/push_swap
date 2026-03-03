/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:14:56 by qbourine          #+#    #+#             */
/*   Updated: 2025/12/01 15:38:01 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;

	i = 0;
	src2 = (const char *) src;
	dest2 = (char *) dest;
	if (dest2 < src2)
	{
		while (i < n)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	else
	{
		while (n--)
			dest2[n] = src2[n];
	}
	return (dest);
}
/*
int main(void)
{
	char dest[] = "\0\0blabla";
	char *src = &dest[2];
	char *result = ft_memmove(dest, src, 7);
	printf("%s", result);
	
	return (0);
	
}*/