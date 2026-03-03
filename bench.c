/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:35:31 by rstrcic           #+#    #+#             */
/*   Updated: 2026/01/08 11:52:10 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_action(char **array, char *action)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (array == NULL)
		return (count);
	while (array[i])
	{
		if (ft_strncmp(array[i], action, ft_strlen(action) + 1) == 0)
			count++;
		i++;
	}
	return (count);
}

void	print_percent(int nbr)
{
	char		*s;
	size_t		i;

	i = 0;
	s = ft_itoa(nbr);
	if (nbr == 0)
	{
		free(s);
		write(2, "0,00%\n", 6);
		return ;
	}
	while (i < ft_strlen(s) - 2)
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, ",", 1);
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, "%\n", 2);
	free(s);
}

char	*determine_strat(int f)
{
	if (f == 11)
		return ("--simple");
	else if (f == 12)
		return ("--medium");
	else if (f == 13)
		return ("--complex");
	return ("--adaptive");
}

void	printblock(char **array)
{
	ft_tprintf("[bench] total_ops: %d\n", count_line(array));
	ft_tprintf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		count_action(array, "sa"), count_action(array, "sb"),
		count_action(array, "ss"),
		count_action(array, "pa"), count_action(array, "pb"));
	ft_tprintf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		count_action(array, "ra"), count_action(array, "rb"),
		count_action(array, "rr"),
		count_action(array, "rra"), count_action(array, "rrb"),
		count_action(array, "rrr"));
}

void	bench(int nbr, char **array, int f )
{
	ft_tprintf("[bench] disorder: ");
	print_percent(nbr);
	if (f == 11)
		ft_tprintf("[bench] strategy: %s / O(n2)\n", determine_strat(f));
	else if (f == 12)
		ft_tprintf("[bench] strategy: %s / O(n√n)\n", determine_strat(f));
	else if (f == 13)
		ft_tprintf("[bench] strategy: %s / O(n log n)\n", determine_strat(f));
	else if (f == 0 || f == 10)
	{
		if (nbr < 2000)
			ft_tprintf("[bench] strategy: %s / O(n2)\n", determine_strat(f));
		else if ((nbr >= 2000) && (nbr < 5000))
			ft_tprintf("[bench] strategy: %s / O(n√n)\n", determine_strat(f));
		else if ((nbr >= 5000) && (nbr <= 10000))
		{
			ft_tprintf("[bench] strategy: %s / O(n log n)\n",
				determine_strat(f));
		}
	}
	printblock(array);
}
