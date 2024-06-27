/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:36:26 by agtshiba          #+#    #+#             */
/*   Updated: 2023/11/03 13:37:35 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	my_printf_hex_upper(unsigned long long nbr)
{
	int	len;

	len = ft_nbrlen_unsigned(nbr, 16);
	if (nbr >= 16)
	{
		my_printf_hex_upper(nbr / 16);
		my_printf_hex_upper(nbr % 16);
	}
	else
	{
		if (nbr > 9)
			nbr += 'A' - '9' - 1;
		my_printf_character(nbr + '0');
	}
	return (len);
}
