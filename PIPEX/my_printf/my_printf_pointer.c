/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:48:44 by agtshiba          #+#    #+#             */
/*   Updated: 2023/11/03 13:51:57 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_putnbr_hex(unsigned long long nbr)
{
	int	len;

	len = ft_nbrlen_unsigned(nbr, 16);
	if (nbr >= 16)
	{
		ft_putnbr_hex(nbr / 16);
		ft_putnbr_hex(nbr % 16);
	}
	else
	{
		if (nbr > 9)
			nbr += 'a' - '9' - 1;
		my_printf_character(nbr + '0');
	}
	return (len);
}

int	ft_put_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (my_printf_string("(nil)"));
	i += my_printf_string("0x");
	i += ft_putnbr_hex(ptr);
	return (i);
}
