/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:30:55 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/10 08:46:52 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cu;

	i = 0;
	str = (unsigned char *) s;
	cu = (unsigned char) c;
	while (i < n)
	{
		if (str[i] != cu)
			i++;
		else
			return (&str[i]);
	}
	return (NULL);
}
/*
int main(void)
{
	printf("%s", (char *)ft_memchr("abcdef", 100, 7));
	return (0);
}*/