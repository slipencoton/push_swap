/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:11:33 by rstrcic           #+#    #+#             */
/*   Updated: 2025/12/09 16:18:31 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_moove(int *tab, int size, int q_next, int q_min)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		if (tab[i] < q_next && tab[i] >= q_min)
			return (-i);
		else if (tab[size - j] < q_next && tab[size - j] >= q_min)
			return (j);
		j++;
		i++;
	}
	return (0);
}

int	max_position(int *b, int lenb)
{
	int	max;
	int	i;
	int	tmp;

	i = 0;
	max = 0;
	tmp = b[0];
	while (i < lenb)
	{
		if (b[i] > tmp)
		{
			max = i;
			tmp = b[i];
		}
		i++;
	}
	if (max > lenb / 2)
		max = max - lenb;
	return (-1 * max);
}

t_list	*phase_b(int *tab, int *b, int size, int lenb)
{
	int		rapide;
	t_list	*mouv;

	mouv = NULL;
	rapide = max_position(b, lenb);
	while (lenb > 0)
	{
		if (rapide == 0)
		{
			ft_lstadd_back(&mouv, ft_lstnew(pa(tab, b, size++, lenb--)));
			rapide = max_position(b, lenb);
		}
		else if (rapide > 0)
		{
			ft_lstadd_back(&mouv, ft_lstnew(rrb(b, lenb)));
			rapide--;
		}
		else
		{
			ft_lstadd_back(&mouv, ft_lstnew(rb(b, lenb)));
			rapide++;
		}
	}
	return (mouv);
}

t_list	*block_cond(int *tab, int size, int q_next, int min)
{
	t_list	*mouv;

	mouv = NULL;
	if ((best_moove(tab, size, q_next, min) > 0))
		ft_lstadd_back(&mouv, ft_lstnew(rra(tab, size)));
	else if (best_moove(tab, size, q_next, min) < 0)
		ft_lstadd_back(&mouv, ft_lstnew(ra(tab, size)));
	return (mouv);
}

char	**block_sort(int *tab, int size, int jump, int min)
{
	int		*b;
	int		lenb;
	int		i;
	int		q_next;
	t_list	*mouv;

	lenb = 0;
	mouv = NULL;
	b = (int *)malloc(sizeof(int) * size);
	while (size > 0)
	{
		i = 0;
		q_next = find_q(tab, size, min, jump);
		while (i < jump && size > 0)
		{
			if ((best_moove(tab, size, q_next, min) == 0) && i++ <= jump)
				ft_lstadd_back(&mouv, ft_lstnew(pb(tab, b, size--, lenb++)));
			else
				ft_lstadd_back(&mouv, block_cond(tab, size, q_next, min));
		}
		min = q_next;
	}
	ft_lstadd_back(&mouv, phase_b(tab, b, size, lenb));
	free(b);
	return (make_array(&mouv));
}

// int main()
// {
// 	 int tab[9] = {6, 8, 1, 7, 4, 3, 10, 9, 2};
// 	 int k;
// 	 char **array;

// 	 k = 0;
// 	 while (k < 9)
// 	 {
// 		 printf("%d ", tab[k]);
// 		 k++;
// 	 }
// 	 printf("\n");

// 	array = block_sort(tab, 9);

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