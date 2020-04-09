/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:28:28 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 21:54:39 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_type(char type, t_format format, va_list args)
{
	int nb_of_printed_chars;

	nb_of_printed_chars = 0;
	if (type == 'c')
		nb_of_printed_chars = print_char(format, args);
	else if (type == 's')
		nb_of_printed_chars = print_string(format, args);
	else if (type == 'p')
		nb_of_printed_chars = print_pointer(format, args);
	else if (type == 'd' || type == 'i')
		nb_of_printed_chars = print_integer(format, args);
	else if (type == 'u')
		nb_of_printed_chars = print_unsigned(format, args);
	else if (type == 'x')
		nb_of_printed_chars = print_hexa(format, args, "0123456789abcdef");
	else if (type == 'X')
		nb_of_printed_chars = print_hexa(format, args, "0123456789ABCDEF");
	else if (type == '%')
		nb_of_printed_chars = print_percent(format);
	return (nb_of_printed_chars);
}

int	fill_in_width(int width, char c)
{
	int nb_of_printed_characters;

	nb_of_printed_characters = 0;
	while (nb_of_printed_characters < width)
	{
		ft_putchar_fd(c, 1);
		nb_of_printed_characters++;
	}
	return (nb_of_printed_characters);
}

int	print_edges(int width, char c)
{
	int nb_of_printed_chars;

	nb_of_printed_chars = 0;
	while (nb_of_printed_chars < width)
	{
		ft_putchar_fd(c, 1);
		nb_of_printed_chars++;
	}
	return (nb_of_printed_chars);
}
