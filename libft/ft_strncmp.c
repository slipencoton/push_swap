/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:55:11 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/10 08:44:33 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (i < n && (s11 || s22))
	{
		if (s11[i] != s22[i])
		{
			return ((unsigned char)s11[i] - (unsigned char)s22[i]);
		}
		i++;
	}
	return (0);
}
/*
int main(void)
{
	printf("%d", ft_strncmp("1234", "1235", 3));
	return(0);
}*/
