/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_hex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:34:38 by agtshiba          #+#    #+#             */
/*   Updated: 2023/11/03 13:35:38 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	my_printf_hex_lower(unsigned long long nbr)
{
	int	len;

	len = ft_nbrlen_unsigned(nbr, 16);
	if (nbr >= 16)
	{
		my_printf_hex_lower(nbr / 16);
		my_printf_hex_lower(nbr % 16);
	}
	else
	{
		if (nbr > 9)
			nbr += 'a' - '9' - 1;
		my_printf_character(nbr + '0');
	}
	return (len);
}
