/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeisp_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:31:48 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 11:36:41 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_pointer(char *output, int i, int print)
{
	if (print)
		write(1, &output[i], 1);
	return (1);
}

int		ptr_precision(char *output, int len, int precision, int print)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (precision > -1 && len <= precision)
		while (output[i])
		{
			if (print)
			{
				while (len++ < precision)
					j += ft_putstr_fd("0", 1);
				write(1, &output[i], 1);
			}
			i++;
		}
	else if (precision > -1 && len > precision)
		while (i - 1 < precision)
			i += put_pointer(output, i, print);
	else
		while (output[i])
			i += put_pointer(output, i, print);
	return (i + j);
}

int		pointer_check_dash(t_format format, int len, char *output)
{
	int	nopc;

	nopc = 0;
	if (format.dash)
	{
		nopc += ft_putstr_fd("0x", 1);
		nopc += ptr_precision(output, len, format.precision, 1);
		nopc += print_edges(format.width - (len + 2), ' ');
	}
	else if (!format.dash)
	{
		nopc += print_edges(format.width - (len + 2), ' ');
		nopc += ft_putstr_fd("0x", 1);
		nopc += ptr_precision(output, len, format.precision, 1);
	}
	return (nopc);
}

char	*is_output(t_format format, unsigned long long input)
{
	char	*output;

	if (!input && !format.precision)
		output = ft_strdup("");
	else if (!input && format.precision)
		output = ft_strdup("0");
	else
		output = ulltoa_base(input, "0123456789abcdef");
	return (output);
}

int		print_pointer(t_format format, va_list args)
{
	char				*output;
	int					len;
	int					nopc;
	unsigned long long	input;
	int					how_many_to_print;

	nopc = 0;
	input = va_arg(args, unsigned long long);
	output = is_output(format, input);
	len = ft_strlen(output);
	how_many_to_print = ptr_precision(output, len, format.precision, 0);
	nopc += pointer_check_dash(format, len, output);
	free(output);
	return (nopc);
}
