/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:35:03 by rstrcic           #+#    #+#             */
/*   Updated: 2026/01/09 12:37:44 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	**flags(char flag, int *array, int size, int disorder)
{
	if (disorder == 0)
		return (NULL);
	else if (size == 3 && disorder > 0)
		return (for_three(array, size));
	else if ((size == 4 || size == 5) && disorder > 0)
		return (under_five(array, size, NULL, 0));
	if (flag == 0 || flag == 10)
	{
		if (disorder < 2000 && disorder > 0)
			return (selection_sort(array, size));
		else if (disorder >= 2000 && disorder < 5000)
			return (block_sort(array, size, 2 * ft_sqrt(size),
					find_min(array, size)));
		else if (disorder >= 5000)
			return (radix_sort(numtoind(array, size), size, size - 1, 0));
	}
	if (flag == 1 || flag == 11)
		return (selection_sort(array, size));
	else if (flag == 2 || flag == 12)
		return (block_sort(array, size, 2 * ft_sqrt(size),
				find_min(array, size)));
	else if (flag == 3 || flag == 13)
		return (radix_sort(numtoind(array, size), size, size - 1, 0));
	return (NULL);
}

int	calc_tmp(char **argv, int argc, int i, int *array)
{
	int		tmp;
	char	**mouvs;

	mouvs = NULL;
	tmp = 0;
	if (ft_strchr(argv[i], ' ') == NULL)
		tmp = compute_disorder(array, argc, i);
	else if (ft_strchr(argv[i], ' ') != NULL)
	{
		mouvs = ft_split(argv[i], ' ');
		tmp = compute_disorder(array, count_split(mouvs), 0);
		free_array(mouvs);
		mouvs = NULL;
	}
	return (tmp);
}

void	choose_print(int f, int tmp, char **mouvs)
{
	printmouv(mouvs);
	if (f >= 10)
		bench(tmp, mouvs, f);
}

int	main(int argc, char **argv)
{
	int		i;
	int		f;
	int		*array;
	int		tmp;
	char	**mouvs;

	f = 0;
	tmp = 0;
	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
		f += identify_if_flag(argv[i++]);
	if (argc <= 1 || i == argc)
		return (1);
	array = make_stack(i, argv, argc);
	if (array == NULL || f < 0)
		return (ft_printf("%s", "Error\n"));
	tmp = calc_tmp(argv, argc, i, array);
	if (ft_strchr(argv[i], ' ') == NULL)
		mouvs = flags(f, array, argc - i, tmp);
	else
		mouvs = flags(f, array, (count_int(argv[i])), tmp);
	free(array);
	choose_print(f, tmp, mouvs);
	free_array(mouvs);
	return (0);
}
