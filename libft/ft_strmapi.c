/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:08:36 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/13 12:20:04 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;
	unsigned int	l;

	i = 0;
	s2 = NULL;
	if (!s)
		return (NULL);
	l = ft_strlen(s);
	s2 = malloc(sizeof(char) * (l + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < l)
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*
int main(void)
{
	printf("%s", ft_strmapi("HELLO wOrLd", ft_tolower));
	return(0);
}

char	ft_tolower(unsigned int i, char c)
{
	unsigned z = i;

	z = z+1;
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}*/