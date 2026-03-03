/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:34:51 by rstrcic           #+#    #+#             */
/*   Updated: 2025/12/02 15:55:33 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rra(int *array, int len)
{
	int	tmp;
	int	i;

	tmp = array[len - 1];
	i = len - 2;
	while (i >= 0)
	{
		array[i + 1] = array[i];
		i--;
	}
	array[0] = tmp;
	return ("rra");
}

char	*rrb(int *array, int len)
{
	int	tmp;
	int	i;

	tmp = array[len - 1];
	i = len - 2;
	while (i >= 0)
	{
		array[i + 1] = array[i];
		i--;
	}
	array[0] = tmp;
	return ("rrb");
}

char	*rrr(int *a, int *b, int lenb, int lena)
{
	rra(a, lena);
	rrb(b, lenb);
	return ("rrr");
}

// int main(void)
// {
//	 int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//	 rrb(a, 9);
//	 return 0;

// }