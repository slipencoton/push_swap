/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:03:06 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/13 12:08:58 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	i;
	size_t	sizee;

	i = 0;
	if (s == NULL)
		return (0);
	sizee = ft_strlen(s);
	if (start >= sizee)
	{
		buff = malloc(1);
		buff[0] = 0;
		return (buff);
	}
	if (len >= sizee)
		len = sizee - start;
	buff = malloc(len + 1);
	if (!buff)
		return (0);
	while (i < len)
		buff[i++] = s[start++];
	buff[i] = 0;
	return (buff);
}

/*
int main(void)
{
	char *s = ft_substr("tripouille", 0, 10);
	printf("%zu", malloc_usable_size(s));
	free(s);
	return (0);
}*/