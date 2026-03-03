/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:30:03 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/10 11:27:14 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	dst_length;

	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	if (dst_length >= size)
		dst_length = size;
	if (dst_length == size)
		return (dst_length + src_length);
	if (src_length < size - dst_length)
		ft_memcpy(dst + dst_length, src, src_length + 1);
	else
	{
		ft_memcpy(dst + dst_length, src, size - dst_length - 1);
		dst[size - 1] = 0;
	}
	return (dst_length + src_length);
}

/*
int main(void)
{
	char	a[32] = "rrrrrrrrrrrrrrr";
	char	b[] = "lorem ipsum dolor sit amet";

	ft_strlcat(a, b, 5);
	printf("%s\n", a);
	printf("%d", ft_strlcat(a, b, 5));
	return (0);
}*/
