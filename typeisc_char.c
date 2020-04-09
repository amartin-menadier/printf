/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeisc_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:52:52 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 21:12:21 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_format format, va_list args)
{
	if (format.dash && format.width)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		fill_in_width(format.width - 1, ' ');
		return (format.width);
	}
	else if (!format.dash && format.width)
		fill_in_width(format.width - 1, ' ');
	ft_putchar_fd(va_arg(args, int), 1);
	if (format.width)
		return (format.width);
	return (1);
}
