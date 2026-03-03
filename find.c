/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:21:32 by rstrcic           #+#    #+#             */
/*   Updated: 2025/12/05 14:30:00 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *tab, int size)
{
	int	min;
	int	i;

	i = 0;
	min = tab[i];
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int	find_max(int *tab, int size)
{
	int	max;
	int	i;

	i = 0;
	max = tab[i];
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	find_q(int *tab, int size, int past_q, int jump)
{
	int	q;
	int	i;
	int	j;
	int	min;

	i = 0;
	q = past_q;
	while (i < jump)
	{
		min = 2147483647;
		j = 0;
		while (j < size)
		{
			if (tab[j] > q && tab[j] < min)
				min = tab[j];
			j++;
		}
		if (min == 2147483647)
			return (q);
		q = min;
		i++;
	}
	return (q);
}

int	find_rev(int *tab, int size, int q_next, int q_min)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[size - i] >= q_min && tab[size - i] < q_next)
			return (i);
		i++;
	}
	return (0);
}

int	find_start(int *tab, int size, int q_next, int q_min)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] >= q_min && tab[i] <= q_next)
			return (i);
		i++;
	}
	return (0);
}
