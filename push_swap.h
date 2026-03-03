/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: qbourine <qbourine@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/11/27 11:51:20 by rstrcic		   #+#	#+#			 */
/*   Updated: 2025/12/02 14:18:05 by qbourine		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

int		compute_disorder(int *a, int argc, int flags);
void	print_percent(int nbr);
char	**make_array(t_list **mouv);
int		*make_stack(int i, char **argv, int argc);
int		ft_strcmp(char *s1, char *s2);
int		identify_if_flag(char *str);
char	*rb(int *array, int len);
char	*ra(int *array, int len);
char	*sa(int *a);
char	*sb(int *b);
char	*ss(int *a, int *b);
char	*rr(int *a, int *b, int lenb, int lena);
char	*rrr(int *a, int *b, int lenb, int lena);
char	*rrb(int *array, int len);
char	*rra(int *array, int len);
char	*pa(int *a, int *b, int lena, int lenb);
char	*pb(int *a, int *b, int lena, int lenb);
char	**selection_sort(int *tab, int size);
int		min_find(int *tab, int len);
void	bench(int nbr, char **array, int f);
char	*determine_strat(int f);
void	print_percent(int nbr);
int		count_action(char **array, char *action);
int		find_min(int *tab, int size);
int		find_max(int *tab, int size);
int		find_q(int *tab, int size, int past_q, int jump);
int		ft_sqrt(int nb);
int		min_position(int *tab, int len);
char	**block_sort(int *tab, int size, int jump, int min);
int		find_rev(int *tab, int size, int q_next, int q_min);
int		find_start(int *tab, int size, int q_next, int q_min);
int		nodupint(int *tab, int size);
int		ft_power(int nb, int power);
int		ft_chrint(int *array, int size, int power, int i);
char	**radix_sort(int *array, int size, int max, int power);
int		position_init(int *array, int size, int initial);
int		count_line(char **array);
int		errorint(int *tab, int size);
int		errorchr(int *tab, int size);
void	free_array(char **tmp);
t_list	*whileloop(int *a, int *b, int size, int lenb);
int		count_int(char *argv);
void	printmouv(char **mouv);
char	**for_three(int *array, int size);
char	**under_five(int *array, int size, t_list *mouv, int lenb);
int		*numtoind(int *a, int size);

#endif