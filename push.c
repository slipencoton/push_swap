/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:22:36 by qbourine          #+#    #+#             */
/*   Updated: 2025/12/09 16:23:28 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*pa(int *a, int *b, int lena, int lenb)
{
	int	i;
	int	temp_val;

	if (lenb <= 0)
		return (NULL);
	temp_val = b[0];
	i = lena;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp_val;
	i = 0;
	while (i < lenb - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = 0;
	return ("pa");
}

char	*pb(int *a, int *b, int lena, int lenb)
{
	int	i;
	int	temp_val;

	if (lena <= 0)
		return (NULL);
	temp_val = a[0];
	i = lenb;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp_val;
	i = 0;
	while (i < lena - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = 0;
	return ("pb");
}

// int main(void)
// {
// 	 int i = 0;
// 	 int lena = 5;
// 	 int lenn = 2;
// 	 int *a;
// 	 int *b;

// 	  a = malloc(sizeof(int) * lena);
// 	  b = malloc(sizeof(int) * lenn);
// 	 while (i < 5)
// 	 {
// 		 a[i] = i;
// 		 i++;
// 	 }
// 	 i = 0;
// 	 while (i < 5)
// 	 {
// 		 printf("a[%d] = %d\n", i, a[i]);
// 		 i++;
// 	 }
// 	 i = 5;
// 	 while (i < 7)
// 	 {
// 		 b[i - 5] = i;
// 		 i++;
// 	 }
// 	 i = 0;
// 	 while (i < 2)
// 	 {
// 		 printf("b[%d] = %d\n", i, b[i]);
// 		 i++;
// 	 }
// 	 pb(a, b, lena, lenn);
// 	 i = 0;
// 	 while (i < 4)
// 	 {
// 		 printf("a[%d] = %d\n", i, a[i]);
// 		 i++;
// 	 }
// 	 i = 0;
// 	 while (i < 3)
// 	 {
// 		 printf("b[%d] = %d\n", i, b[i]);
// 		 i++;
// 	 }
// 	 return 0;
// }
