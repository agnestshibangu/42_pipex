/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:55:31 by agtshiba          #+#    #+#             */
/*   Updated: 2023/11/03 13:56:30 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	my_printf_unsigned(unsigned int nbr)
{
	if (nbr >= 10)
	{
		my_printf_unsigned(nbr / 10);
		my_printf_unsigned(nbr % 10);
	}
	else
		my_printf_character(nbr + '0');
	return (ft_nbrlen_unsigned(nbr, 10));
}
