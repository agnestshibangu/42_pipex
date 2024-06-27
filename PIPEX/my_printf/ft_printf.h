/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:43:37 by agtshiba          #+#    #+#             */
/*   Updated: 2023/11/13 09:35:39 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int		ft_printf(char const *str, ...);
int		my_printf_character(int c);
int		my_printf_string(char *str);
int		my_printf_number(int num);
size_t	ft_nbrlen_unsigned(unsigned long long nbr, int base);
int		my_printf_unsigned(unsigned int nbr);
int		my_printf_hex_lower(unsigned long long nbr);
int		my_printf_hex_upper(unsigned long long nbr);
int		ft_putnbr_hex(unsigned long long nbr);
int		ft_put_ptr(unsigned long long ptr);

#endif
