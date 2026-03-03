/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:56:07 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/13 12:21:32 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int main(void)
{
	char	s[] = "this in uppercase";
	
	ft_striteri(s, ft_toupper);
	printf("%s", s);
	return (0);
}

void	ft_toupper(unsigned int i, char *c)
{
	unsigned int j = i;

	j = 0;
	if (*c >= 'a' && *c <= 'z')
	{
		*c -= 32;
	}
}*/