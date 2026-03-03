/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbourine <qbourine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:49:04 by rstrcic           #+#    #+#             */
/*   Updated: 2025/12/10 14:40:51 by qbourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *string, ...);
int		ft_putchar(int c);
int		ft_tprintf(const char *string, ...);
int		ft_tputchar(int c);
int		print_str(char *str);
int		print_hex(unsigned int nbr, char format);
char	*ft_caps_hex_itoa(unsigned int n);
char	*ft_hex_itoa(unsigned int n);
int		ft_hex_len(unsigned int nbr);
int		ft_putstr(char *str);
int		print_int(int nbr);
int		get_param(va_list args, char format);
int		print_unsigned(unsigned int nbr);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_unsigned_len(unsigned int nbr);
int		print_hex_ptr(unsigned long int nbr);
char	*ft_caps_hex_ptr_itoa(unsigned long int n);
char	*ft_hex_ptr_itoa(unsigned long int n);
int		ft_hex_ptr_len(unsigned long int nbr);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_tparam(va_list args, char format);
int		print_tunsigned_int(unsigned int nbr);
int		print_tstr(char *str);
int		ft_tputstr(char *str);
int		print_thex_ptr(unsigned long int nbr);
int		print_tint(int nbr);
char	*ft_get_hex_str(unsigned int n, char *base);

#endif