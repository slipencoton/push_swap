/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 08:07:13 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/10 08:44:19 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	conv;
	char	*tmp;
	char	*ptr;

	i = 0;
	conv = (char) c;
	tmp = (char *)s;
	ptr = NULL;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == conv)
			ptr = &tmp[i];
		i++;
	}
	if (tmp[i] == conv)
		ptr = &tmp[i];
	return (ptr);
}
/*
int main(void)
{
	char *buff = ft_strrchr("abcdefeff", 101);
	printf("%s", buff);
	return (0);
}*/