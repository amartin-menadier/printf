/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeisxX_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:00:05 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 21:14:14 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_edges(t_format format, int len)
{
	int	nb_of_prntd_chars;

	nb_of_prntd_chars = 0;
	if (format.zero && !format.dash && format.precision < 0)
		nb_of_prntd_chars += print_edges(format.width - len, '0');
	else if (format.precision >= len)
		nb_of_prntd_chars += print_edges(format.width - format.precision, ' ');
	else
		nb_of_prntd_chars += print_edges(format.width - len, ' ');
	return (nb_of_prntd_chars);
}

int	hexa_precision(int precision, int len)
{
	int	i;

	i = 0;
	if (precision)
		while (i < precision - len)
		{
			write(1, "0", 1);
			i++;
		}
	return (i);
}

int	check_hexa_dash(t_format format, int len, char *str)
{
	int	nb_of_printed_chars;

	nb_of_printed_chars = 0;
	if (format.dash)
	{
		nb_of_printed_chars += hexa_precision(format.precision, len);
		nb_of_printed_chars += ft_putstr_fd(str, 1);
		nb_of_printed_chars += hexa_edges(format, len);
	}
	else if (!format.dash)
	{
		nb_of_printed_chars += hexa_edges(format, len);
		nb_of_printed_chars += hexa_precision(format.precision, len);
		nb_of_printed_chars += ft_putstr_fd(str, 1);
	}
	return (nb_of_printed_chars);
}

int	print_hexa(t_format format, va_list args, char *base)
{
	int				nb_of_printed_chars;
	char			*output;
	int				len_output;
	unsigned int	input;

	nb_of_printed_chars = 0;
	input = va_arg(args, unsigned int);
	if (!input)
		output = ft_strdup("0");
	else
		output = ft_itoa_base(input, base);
	len_output = ft_strlen(output);
	if (format.precision == 0 && *output == '0')
	{
		nb_of_printed_chars += print_edges(format.width, ' ');
		return (nb_of_printed_chars);
	}
	nb_of_printed_chars += check_hexa_dash(format, len_output, output);
	free(output);
	return (nb_of_printed_chars);
}
