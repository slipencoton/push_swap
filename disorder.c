/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:35:25 by rstrcic           #+#    #+#             */
/*   Updated: 2026/01/05 15:59:24 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(int *a, int argc, int flags)
{
	long long	mistakes;
	long long	total_pairs;
	int			i;
	int			j;
	int			res;

	mistakes = 0;
	total_pairs = 0;
	i = -1;
	if (argc == 2)
		return (0);
	while (++i <= argc - flags - 1)
	{
		j = i;
		while (++j <= argc - flags - 1)
		{
			total_pairs += 1;
			if (a[i] > a[j])
				mistakes += 1;
		}
	}
	if (total_pairs == 0)
		total_pairs = 1;
	res = ((mistakes * 10000) / total_pairs);
	return (res);
}

// int main(void)
// {
// 	int a[8] = {8, 7,6,5,4,3,2,1};
// 	printf("%d", compute_disorder(a, 9, 0));
// 	return 0;
// }