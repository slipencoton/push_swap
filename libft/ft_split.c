/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:18:59 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/12 13:50:06 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	tab = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (j < ft_strlen(s))
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (i - j != 0)
				tab[k++] = ft_substr(s, j, i - j);
			j = i + 1;
		}
		i++;
	}
	tab[k] = NULL;
	return (tab);
}

/*
int	main(void)
{
	char **tab;
	tab = ft_split("tripouille", ' ');
	if (tab[1] == NULL)
		printf("OK");
	free(tab);
	return (0);
}*/