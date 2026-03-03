/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:17:56 by qbourine          #+#    #+#             */
/*   Updated: 2025/11/11 09:05:45 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*module;

	module = malloc(sizeof(t_list));
	if (!module)
		return (NULL);
	module->content = content;
	module->next = NULL;
	return (module);
}
