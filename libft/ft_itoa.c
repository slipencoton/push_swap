/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:47:34 by qbourine          #+#    #+#             */
/*   Updated: 2025/12/09 15:21:34 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(int n)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = n;
	if (n == 0)
		return (1);
	if (tmp < 0)
	{
		i++;
	}
	while (tmp)
	{
		tmp = tmp / 10;
		i++;
	}
	return (i);
}

int	ft_power(int nb, int power)
{
	int	t;

	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	else
	{
		t = nb;
		while (power > 1)
		{
			nb = nb * t;
			power --;
		}
		return (nb);
	}
}

char	*ft_itoa(int n)
{
	char		*s;
	long int	i;
	long int	c;
	long int	nl;

	i = 0;
	c = count(n);
	nl = (long int) n;
	s = malloc(c + 1);
	if (s == 0)
		return (0);
	if (nl == 0)
		s[i++] = 48;
	if (nl < 0)
	{
		nl = nl * -1;
		s[i++] = 45;
	}
	while (i < c)
	{
		s[i] = ((nl / ft_power(10, c - i - 1)) % 10) + 48;
		i++;
	}
	s[i] = 0;
	return (s);
}
/*
int main(void)
{
	char *s = ft_itoa(-2147483648);
	printf("%s", s);
	free(s);
	return(0);
}*/