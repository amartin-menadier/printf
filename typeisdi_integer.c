/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeisdi_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:24:14 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 21:13:27 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_edges(t_format format, int len, int d_or_i)
{
	int nopc;

	nopc = 0;
	if (format.zero)
	{
		if (d_or_i < 0)
		{
			write(1, "-", 1);
			nopc++;
		}
		nopc += print_edges(format.width - len, '0');
	}
	else if (format.precision >= len)
	{
		if (d_or_i < 0)
			nopc += print_edges(format.width - format.precision - 1, ' ');
		else
			nopc += print_edges(format.width - format.precision, ' ');
	}
	else
		nopc += print_edges(format.width - len, ' ');
	return (nopc);
}

int		int_precision(t_format format, int len, int d_or_i)
{
	int i;
	int nb_of_printed_chars;

	i = 0;
	nb_of_printed_chars = 0;
	if (d_or_i < 0 && format.precision < len && !format.zero)
	{
		write(1, "-", 1);
		return (1);
	}
	if (format.precision > 0)
	{
		if (d_or_i < 0)
		{
			write(1, "-", 1);
			nb_of_printed_chars++;
			i--;
		}
		while (i++ < format.precision - len)
		{
			write(1, "0", 1);
			nb_of_printed_chars++;
		}
	}
	return (nb_of_printed_chars);
}

int		check_int_dash(t_format format, int len, char *output, int d_or_i)
{
	int	nb_of_printed_chars;

	nb_of_printed_chars = 0;
	if (d_or_i < 0)
		output++;
	if (format.dash)
	{
		nb_of_printed_chars += int_precision(format, len, d_or_i);
		nb_of_printed_chars += ft_putstr_fd(output, 1);
		nb_of_printed_chars += int_edges(format, len, d_or_i);
	}
	else if (!format.dash)
	{
		nb_of_printed_chars += int_edges(format, len, d_or_i);
		nb_of_printed_chars += int_precision(format, len, d_or_i);
		nb_of_printed_chars += ft_putstr_fd(output, 1);
	}
	return (nb_of_printed_chars);
}

int		print_integer(t_format format, va_list args)
{
	int		d_or_i;
	char	*output;
	int		int_len;
	int		nb_of_printed_chars;

	d_or_i = va_arg(args, int);
	output = ft_itoa(d_or_i);
	int_len = ft_strlen(output);
	nb_of_printed_chars = 0;
	if (format.zero && (format.dash || format.precision >= 0))
		format.zero = 0;
	if (format.precision == 0 && *output == '0')
	{
		nb_of_printed_chars += print_edges(format.width, ' ');
		return (nb_of_printed_chars);
	}
	nb_of_printed_chars += check_int_dash(format, int_len, output, d_or_i);
	free(output);
	return (nb_of_printed_chars);
}
