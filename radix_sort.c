/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:56:53 by rstrcic           #+#    #+#             */
/*   Updated: 2026/01/05 14:03:31 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*phase_1(int *a, int size, int pos, int i)
{
	t_list	*mouv;

	mouv = NULL;
	i++;
	while (a[0] != pos)
	{
		if (position_init(a, size, pos) <= size / 2)
			ft_lstadd_back(&mouv, ft_lstnew(ra(a, size)));
		if (position_init(a, size, pos) > size / 2)
			ft_lstadd_back(&mouv, ft_lstnew(rra(a, size)));
	}
	return (mouv);
}

t_list	*phase_2(int *b, int lenb, int pos, int i)
{
	t_list	*mouv;

	mouv = NULL;
	i--;
	while (b[0] != pos)
	{
		if (position_init(b, lenb, pos) <= lenb / 2)
			ft_lstadd_back(&mouv, ft_lstnew(rb(b, lenb)));
		if (position_init(b, lenb, pos) > lenb / 2)
			ft_lstadd_back(&mouv, ft_lstnew(rrb(b, lenb)));
	}
	return (mouv);
}

t_list	*phase_1b(int *a, int *b, int size, int pow)
{
	int		i;
	int		pos;
	int		lenb;
	t_list	*mouv;

	pos = a[0];
	i = -9;
	lenb = 0;
	mouv = NULL;
	while (size > 0)
	{
		if (a[0] % ft_power(10, pow + 1) / ft_power(10, pow) == i)
			ft_lstadd_back(&mouv, ft_lstnew(pb(a, b, size--, lenb++)));
		else if (ft_chrint(a, size, pow, i) == 1 && size)
			ft_lstadd_back(&mouv, phase_1(a, size, pos, i++));
		else
			ft_lstadd_back(&mouv, ft_lstnew(ra(a, size)));
		if (lenb > 0 && b[0] == pos && size > 0)
			pos = a[0];
	}
	return (mouv);
}

t_list	*phase_2b(int *a, int *b, int lenb, int pow)
{
	int		i;
	int		pos;
	int		size;
	t_list	*mouv;

	size = 0;
	mouv = NULL;
	pos = b[0];
	i = 9;
	while (lenb > 0)
	{
		if (b[0] % ft_power(10, pow + 1) / ft_power(10, pow) == i)
			ft_lstadd_back(&mouv, ft_lstnew(pa(a, b, size++, lenb--)));
		else if (ft_chrint(b, lenb, pow, i) == 1 && lenb)
			ft_lstadd_back(&mouv, phase_2(b, lenb, pos, i--));
		else
			ft_lstadd_back(&mouv, ft_lstnew(rb(b, lenb)));
		if (a[0] == pos)
			pos = b[0];
	}
	return (mouv);
}

char	**radix_sort(int *a, int size, int max, int pow)
{
	int		*b;
	int		lenb;
	t_list	*mouv;

	lenb = 0;
	mouv = NULL;
	b = (int *)malloc(sizeof(int) * size);
	while (max / ft_power(10, pow))
	{
		if (pow % 2 == 0)
		{
			ft_lstadd_back(&mouv, phase_1b(a, b, size, pow));
			lenb = size;
		}
		else
		{
			ft_lstadd_back(&mouv, phase_2b(a, b, lenb, pow));
			lenb = 0;
		}
		pow++;
	}
	ft_lstadd_back(&mouv, whileloop(a, b, size, lenb));
	free(b);
	free(a);
	return (make_array(&mouv));
}

// int main()
// {
// 	 int tab[9] = {50, 9, 4, 6, 7, 2, 1, 8, 3};
// 	 int k;
// 	 char **array;

// 	 k = 0;
// 	 while (k < 9)
// 	 {
// 		 printf("%d ", tab[k]);
// 		 k++;
// 	 }
// 	 printf("\n");

// 	array = radix_sort(tab, 9);

// 	 k = 0;
// 	 while (k < 9)
// 	 {
// 		 printf("%d ", tab[k]);
// 		 k++;
// 	 }
// 	 printf("\n");
// 	 k = 0;
// 	 while (array[k])
// 	 {
// 		printf("%s\n", array[k]);
// 		k++;
// 	 }
// 	 return (0);
// }