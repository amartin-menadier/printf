/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeisu_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:45:19 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 21:13:51 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_egdes(t_format format, int len)
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

int	unsigned_precision(int precision, int len)
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

int	check_unsigned_dash(t_format format, int len, char *output)
{
	int	nb_of_printed_chars;

	nb_of_printed_chars = 0;
	if (format.dash)
	{
		nb_of_printed_chars += unsigned_precision(format.precision, len);
		nb_of_printed_chars += ft_putstr_fd(output, 1);
		nb_of_printed_chars += unsigned_egdes(format, len);
	}
	else if (!format.dash)
	{
		nb_of_printed_chars += unsigned_egdes(format, len);
		nb_of_printed_chars += unsigned_precision(format.precision, len);
		nb_of_printed_chars += ft_putstr_fd(output, 1);
	}
	return (nb_of_printed_chars);
}

int	print_unsigned(t_format format, va_list args)
{
	char	*output;
	int		len;
	int		nb_of_printed_chars;

	output = ft_utoa(va_arg(args, unsigned int));
	len = ft_strlen(output);
	nb_of_printed_chars = 0;
	if (format.precision == 0 && *output == '0')
	{
		nb_of_printed_chars += print_edges(format.width, ' ');
		return (nb_of_printed_chars);
	}
	nb_of_printed_chars += check_unsigned_dash(format, len, output);
	free(output);
	return (nb_of_printed_chars);
}
