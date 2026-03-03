/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:19:46 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/13 13:06:43 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (ft_calloc(1, 1));
	if (!s1 && s2)
		return (ft_strdup((char *)s2));
	if (!s2 && s1)
		return (ft_strdup((char *)s1));
	s = ft_calloc((int)ft_strlen(s1) + (int)ft_strlen(s2) + 1, 1);
	if (s == NULL)
		return (NULL);
	while (s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	return (s);
}
