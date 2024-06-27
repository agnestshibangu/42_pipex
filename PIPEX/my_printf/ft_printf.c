/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:57:21 by agtshiba          #+#    #+#             */
/*   Updated: 2023/11/21 12:52:11 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list arg, const char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result = my_printf_character(va_arg(arg, int));
	else if (format == 's')
		result = my_printf_string(va_arg(arg, char *));
	else if (format == 'd' || format == 'i')
		result = my_printf_number(va_arg(arg, int));
	else if (format == 'u')
		result = my_printf_unsigned(va_arg(arg, unsigned int));
	else if (format == 'X')
		result = my_printf_hex_upper(va_arg(arg, unsigned int));
	else if (format == 'x')
		result = my_printf_hex_lower(va_arg(arg, unsigned int));
	else if (format == '%')
		result = my_printf_character('%');
	else if (format == 'p')
		return (ft_put_ptr(va_arg(arg, unsigned long long)));
	return (result);
}

int	ft_printf(char const *str, ...)
{
	va_list		arg;
	int			i;
	int			print_len;

	i = 0;
	print_len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_format(arg, str[i + 1]);
			i += 2;
		}
		else
		{
			print_len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(arg);
	return (print_len);
}

// int	main(void)
// {
//     char *str;
//     str = "coucou";

// 	ft_printf("%s\n", str);
// 	return (0);
// }