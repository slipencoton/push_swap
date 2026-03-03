/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:34:43 by rstrcic           #+#    #+#             */
/*   Updated: 2025/12/02 15:55:34 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ra(int *array, int len)
{
	int	tmp;
	int	i;

	tmp = array[0];
	i = 0;
	while (i != len - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = tmp;
	return ("ra");
}

char	*rb(int *array, int len)
{
	int	tmp;
	int	i;

	tmp = array[0];
	i = 0;
	while (i != len - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = tmp;
	return ("rb");
}

char	*rr(int *a, int *b, int lenb, int lena)
{
	ra(a, lena);
	rb(b, lenb);
	return ("rr");
}

// int main(void)
// {
//	 int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//	 ra(a, 9);
//	 return 0;

// }