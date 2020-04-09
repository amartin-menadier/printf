/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:26:23 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 21:11:38 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	initialize_format(t_format format)
{
	format.dash = 0;
	format.zero = 0;
	format.width = 0;
	format.point = 0;
	format.precision = -1;
	format.advance = 0;
	return (format);
}

int			is_format(char c)
{
	if (c == '-' || c == '.' || c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

t_format	format_when_asterisk(t_format format, va_list args)
{
	if (format.point)
		format.precision = va_arg(args, int);
	else if (!format.width)
	{
		format.width = va_arg(args, int);
		if (format.width < 0)
		{
			format.width *= -1;
			format.dash = 1;
		}
	}
	return (format);
}

t_format	fill_in_format(char c, t_format format, va_list args)
{
	if (c == '-')
		format.dash = 1;
	else if (c == '0' && !format.width && !format.point)
		format.zero = 1;
	else if (ft_isdigit(c) && !format.point)
		format.width = (format.width * 10) + (c - '0');
	else if (c == '.')
	{
		format.point = 1;
		format.precision = 0;
	}
	else if (ft_isdigit(c) && format.point)
		format.precision = (format.precision * 10) + (c - '0');
	else if (c == '*')
		format = format_when_asterisk(format, args);
	return (format);
}

t_format	parse_format(const char *instruction, t_format format, va_list args)
{
	int	i;

	i = 0;
	format = initialize_format(format);
	while (instruction[i] && is_format(instruction[i]))
	{
		format = fill_in_format(instruction[i], format, args);
		i++;
	}
	return (format);
}
