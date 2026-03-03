/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:39:03 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/28 16:05:07 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cmp_char(char a, char const *charset)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	while (charset[i])
	{
		if (a == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	if (set == NULL)
		return (ft_strdup((char *)s1));
	j = ft_strlen(s1);
	while (ft_cmp_char(s1[i], set) == 1 && j > i)
		i++;
	while (ft_cmp_char(s1[j], set) == 1 && j > i)
		j--;
	if (i - j == 0 && ft_cmp_char(s1[j], set) == 1)
		return (ft_calloc(1, 1));
	s = ft_calloc((int)j - (int)i + 2, 1);
	if (s == NULL)
		return (NULL);
	while (i <= j)
		s[k++] = s1[i++];
	return (s);
}
/*
int main(void)
{
	char *s = ft_strtrim("teeeeeeeeeeeeee", "te");
	printf("%s", s);
	free(s);
	return (0);
}*/