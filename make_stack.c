/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:35:08 by rstrcic           #+#    #+#             */
/*   Updated: 2026/01/05 14:19:03 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strisnum(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if ((tmp[i] < '0' || tmp[i] > '9') && tmp[i] != '-' && tmp[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	make_a(char **tmp, int i, int *array, int flag)
{
	int		j;
	ssize_t	t;

	j = -1;
	while (tmp[i + ++j])
	{
		if (strisnum(tmp[i + j]) == 1)
		{
			free(array);
			if (flag == 1)
				free_array(tmp);
			return (0);
		}
		t = ft_atoi(tmp[i + j]);
		if (t > 2147483647 || t < -2147483648
			|| (t == 0 && (tmp[i + j][0] != '0' && tmp[i + j][1] != '0')))
		{
			free(array);
			if (flag == 1)
				free_array(tmp);
			return (0);
		}
		array[j] = (int )t;
	}
	return (j);
}

int	*if_free_condition(int j, int *array, int flag, char **tmp)
{
	if (j == 0)
		return (NULL);
	if (nodupint(array, j) == 1)
	{
		free(array);
		if (flag == 1)
			free_array(tmp);
		return (NULL);
	}
	if (flag == 1)
		free_array(tmp);
	return (array);
}

int	*make_stack(int i, char **argv, int argc)
{
	int		*array;
	int		j;
	char	**tmp;
	int		flag;

	j = 0;
	flag = 0;
	if (ft_strchr(argv[i], ' ') != NULL)
	{
		tmp = ft_split(argv[i], ' ');
		i = 0;
		while (tmp[j])
			j++;
		array = malloc(j * sizeof(int));
		flag = 1;
	}
	else
	{
		tmp = argv;
		array = malloc((argc - i) * sizeof(int));
	}
	j = make_a(tmp, i, array, flag);
	return (if_free_condition(j, array, flag, tmp));
}

int	*numtoind(int *a, int size)
{
	int	*ind;
	int	i;
	int	j;
	int	k;

	ind = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		j = 0;
		k = 0;
		while (k < size)
		{
			if (a[k] < a[i])
				j++;
			k++;
		}
		ind[i] = j;
		i++;
	}
	return (ind);
}

// int main(void)
// {   
// 	 int i = 0;
// 	 char **str = ft_split("1 2 3 4 b 6 7 8 9 10 11 12 13 14", ' ');
// 	int *a = make_stack(0, str, 2);
// 	if (!a)
// 		return (ft_printf("error"));
// 	while (i < 13)
// 		ft_printf("%d\n", a[i++]);
// 	return (0);
// }