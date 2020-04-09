/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:24:18 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 21:11:56 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	simple_print(char c)
{
	if (c != '%')
	{
		write(1, &c, 1);
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *instruction, ...)
{
	va_list		args;
	t_format	format;
	int			nb_of_printed_chars;
	int			i;

	i = 0;
	nb_of_printed_chars = 0;
	va_start(args, instruction);
	while (instruction[i])
	{
		nb_of_printed_chars += simple_print(instruction[i]);
		if (instruction[i] == '%' && instruction[i + 1])
		{
			format = parse_format(&instruction[++i], format, args);
			while (is_format(instruction[i]))
				i++;
			if (!instruction[i])
				return (0);
			nb_of_printed_chars += parse_type(instruction[i], format, args);
			i += format.advance;
		}
		i++;
	}
	va_end(args);
	return (nb_of_printed_chars);
}
