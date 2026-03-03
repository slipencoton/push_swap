/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:40:24 by rstrcic           #+#    #+#             */
/*   Updated: 2025/12/10 10:05:04 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*whileloop(int *a, int *b, int size, int lenb)
{
	t_list	*mouv;

	mouv = NULL;
	while (lenb > 0)
	{
		ft_lstadd_back(&mouv, ft_lstnew(pa(a, b, size - lenb, lenb)));
		lenb--;
	}
	return (mouv);
}
