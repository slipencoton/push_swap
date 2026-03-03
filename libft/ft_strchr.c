/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:07:20 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/10 08:45:51 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	conv;
	char	*tmp;

	i = 0;
	conv = (char) c;
	tmp = (char *)s;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == conv)
			return (&tmp[i]);
		i++;
	}
	if (tmp[i] == conv)
		return (&tmp[i]);
	return (NULL);
}
/*
int main(void)
{
	printf("%s", ft_strchr("abcdef", 101));
	return (0);
}*/