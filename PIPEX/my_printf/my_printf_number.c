/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:38:05 by agtshiba          #+#    #+#             */
/*   Updated: 2023/11/03 14:08:17 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	my_printf_number(int nb)
{
	int			i;
	long int	num;

	num = nb;
	i = 0;
	if (num < 0)
	{
		i += my_printf_character('-');
		num *= -1;
	}
	if (num >= 10)
	{
		i += my_printf_number(num / 10);
		i += my_printf_number(num % 10);
	}
	else
		i += my_printf_character(num + '0');
	return (i);
}
