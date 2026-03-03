/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:24:10 by qbourine          #+#    #+#             */
/*   Updated: 2026/01/08 09:52:12 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*for_three_1(int *array, int size)
{
	t_list	*mouv;

	mouv = NULL;
	if (min_position(array, size) == 0)
		ft_lstadd_back(&mouv, ft_lstnew(ra(array, size)));
	else if (min_position(array, size) == 1)
		ft_lstadd_back(&mouv, ft_lstnew(rra(array, size)));
	if (array[0] > array[1])
		ft_lstadd_back(&mouv, ft_lstnew(sa(array)));
	ft_lstadd_back(&mouv, ft_lstnew(rra(array, size)));
	return (mouv);
}

char	**for_three(int *array, int size)
{
	t_list	*mouv;
	char	**tab;

	mouv = NULL;
	mouv = for_three_1(array, size);
	tab = make_array(&mouv);
	ft_lstclear(&mouv, NULL);
	return (tab);
}

t_list	*backa(int *array, int *b, int size, int lenb)
{
	t_list	*mouv;

	mouv = NULL;
	while (lenb > 0)
	{
		if (find_min(array, size) > b[0] && find_min(array, size) == array[0])
			ft_lstadd_back(&mouv, ft_lstnew(pa(array, b, size++, lenb--)));
		else if (find_max(array, size) > b[0] && b[0] < array[0]
			&& b[0] > array[size - 1])
			ft_lstadd_back(&mouv, ft_lstnew(pa(array, b, size++, lenb--)));
		else if (find_max(array, size) > b[0])
			ft_lstadd_back(&mouv, ft_lstnew(ra(array, size)));
		else if (find_max(array, size) < b[0]
			&& find_min(array, size) == array[0])
		{
			ft_lstadd_back(&mouv, ft_lstnew(pa(array, b, size++, lenb--)));
			ft_lstadd_back(&mouv, ft_lstnew(ra(array, size)));
		}
		else if (find_max(array, size) < b[0]
			&& find_min(array, size) != array[0])
			ft_lstadd_back(&mouv, ft_lstnew(ra(array, size)));
	}
	while (find_min(array, size) != array[0])
		ft_lstadd_back(&mouv, ft_lstnew(ra(array, size)));
	return (mouv);
}

char	**under_five(int *array, int size, t_list *mouv, int lenb)
{
	int		*b;
	t_list	*tmp;
	int		i_size;
	char	**tab;

	i_size = size;
	b = (int *)malloc(sizeof(int) * (size - 3));
	while (size > 3)
		ft_lstadd_back(&mouv, ft_lstnew(pb(array, b, size--, lenb++)));
	ft_lstadd_back(&mouv, for_three_1(array, size));
	tmp = mouv;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "sa", 2) == 0 && lenb < 1 && b[0] > b[1])
		{
			sb(b);
			tmp->content = "ss";
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(&mouv, backa(array, b, size, lenb));
	free(b);
	tab = make_array(&mouv);
	ft_lstclear(&mouv, NULL);
	return (tab);
}
