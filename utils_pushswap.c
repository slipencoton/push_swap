/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pushswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:34:35 by rstrcic           #+#    #+#             */
/*   Updated: 2026/01/05 16:06:58 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_init(int *array, int size, int initial)
{
	int	i;

	i = 0;
	while (i < size)
		if (array[i++] == initial)
			return (i);
	return (0);
}

int	ft_chrint(int *array, int size, int power, int i)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (array[j] % (ft_power(10, power + 1)) / ft_power(10, power) == i)
			return (0);
		j++;
	}
	return (1);
}

int	count_line(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (i);
	while (array[i])
		i++;
	return (i);
}

int	count_int(char *argv)
{
	int	i;
	int	count;

	count = 1;
	i = 1;
	while (argv[i++])
	{
		if (((argv[i] <= '9' && argv[i] >= '0') || argv[i] == '-')
			&& argv[i - 1] == ' ')
			count++;
	}
	return (count);
}

void	printmouv(char **mouv)
{
	int	i;

	i = 0;
	if (mouv == NULL)
		return ;
	while (mouv[i])
	{
		ft_printf("%s\n", mouv[i]);
		i++;
	}
}
