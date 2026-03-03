/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:34:29 by rstrcic           #+#    #+#             */
/*   Updated: 2025/12/09 16:47:07 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_position(int *tab, int len)
{
	int	min;
	int	i;
	int	tmp;

	i = 0;
	min = 0;
	tmp = tab[0];
	while (i < len)
	{
		if (tab[i] < tmp)
		{
			min = i;
			tmp = tab[i];
		}
		i++;
	}
	return (min);
}

char	**make_array(t_list **mouv)
{
	char	**array;
	t_list	*node;
	int		i;

	array = malloc(sizeof(char *) * (ft_lstsize(*mouv) + 1));
	i = 0;
	node = *mouv;
	while (node)
	{
		array[i++] = ft_strdup(node->content);
		node = node->next;
	}
	array[i] = NULL;
	ft_lstclear(&node, NULL);
	ft_lstclear(mouv, NULL);
	return (array);
}

char	**selection_sort(int *tab, int size)
{
	int		lenb;
	int		*b;
	t_list	*mouv;
	int		i_size;
	char	**array;

	i_size = size;
	lenb = 0;
	mouv = NULL;
	b = (int *)malloc(sizeof(int) * i_size);
	while (size > 1)
	{
		if (min_position(tab, size) == 0)
			ft_lstadd_back(&mouv, ft_lstnew(pb(tab, b, size--, lenb++)));
		else if (min_position(tab, size) <= size / 2)
			ft_lstadd_back(&mouv, ft_lstnew(ra(tab, size)));
		else if (min_position(tab, size) > size / 2)
			ft_lstadd_back(&mouv, ft_lstnew(rra(tab, size)));
	}
	while (lenb > 0)
		ft_lstadd_back(&mouv, ft_lstnew(pa(tab, b, size++, lenb--)));
	free(b);
	array = make_array(&mouv);
	ft_lstclear(&mouv, NULL);
	return (array);
}

// int main()
// {
// 	 int tab[4] = {4, 3, 2, 1};
// 	 int k;
// 	 char **array;

// 	 k = 0;
// 	 while (k < 4)
// 	 {
// 		 printf("%d ", tab[k]);
// 		 k++;
// 	 }
// 	 printf("\n");

// 	 array = selection_sort(tab, 4);

// 	 k = 0;
// 	 while (k < 4)
// 	 {
// 		 printf("%d ", tab[k]);
// 		 k++;
// 	 }
// 	 printf("\n");
// 	 k = -1;
// 	 while (array[k++])
// 		 printf("%s\n", array[k]);
// 	 return (0);
// }