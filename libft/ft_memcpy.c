/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:32:03 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/10 08:46:45 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;

	i = 0;
	src2 = (const char *) src;
	dest2 = (char *) dest;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}

/*
int main(void)
{
	char dest[] = "blabla";
	char src[] = "tototo";
	char *res = ft_memcpy(dest, src, 4);
	
	return (0);
	
}*/