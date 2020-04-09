/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeiss_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:20:50 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 21:12:48 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		str_precision(char *str, int len, int precision, int print)
{
	int	i;

	i = 0;
	if (precision > -1 && len <= precision)
		while (str[i])
		{
			if (print)
				write(1, &str[i], 1);
			i++;
		}
	else if (precision > -1 && len > precision)
		while (i < precision)
		{
			if (print)
				write(1, &str[i], 1);
			i++;
		}
	else
		while (str[i])
		{
			if (print)
				write(1, &str[i], 1);
			i++;
		}
	return (i);
}

int		str_edges(int zero, int width, int print)
{
	int	nopc;

	nopc = 0;
	if (zero && print)
		nopc += print_edges(width, '0');
	else
		nopc += print_edges(width, ' ');
	return (nopc);
}

char	*is_string(char *str, t_format format)
{
	if (!str && format.precision)
		str = ft_strdup("(null)");
	else if (!str && !format.precision)
		str = ft_strdup("");
	return (str);
}

int		print_string(t_format format, va_list args)
{
	char	*str;
	int		len;
	int		nopc;
	int		how_many_to_print;

	nopc = 0;
	str = va_arg(args, char *);
	str = is_string(str, format);
	len = ft_strlen(str);
	how_many_to_print = str_precision(str, len, format.precision, 0);
	if (format.dash && format.width > how_many_to_print)
	{
		nopc += str_precision(str, len, format.precision, 1);
		nopc += str_edges(format.zero, (format.width - how_many_to_print), 0);
	}
	else if (!format.dash && format.width > how_many_to_print)
	{
		nopc += str_edges(format.zero, (format.width - how_many_to_print), 1);
		nopc += str_precision(str, len, format.precision, 1);
	}
	else
		nopc += str_precision(str, len, format.precision, 1);
	return (nopc);
}
