/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:35:13 by rstrcic           #+#    #+#             */
/*   Updated: 2026/01/08 10:34:13 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	identify_if_flag(char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return (1);
	else if (ft_strcmp(str, "--medium") == 0)
		return (2);
	else if (ft_strcmp(str, "--complex") == 0)
		return (3);
	else if (ft_strcmp(str, "--adaptive") == 0)
		return (0);
	else if (ft_strcmp(str, "--bench") == 0)
		return (10);
	else
		return (-15);
	return (0);
}

// int main(void)
// {
//	 ft_printf("%d", identify_if_flag(" "));
//	 return 0;
// }