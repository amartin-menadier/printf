/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeispercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:56:14 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 21:14:45 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_format format)
{
	int					nb_of_printed_chars;

	nb_of_printed_chars = 0;
	if (format.dash)
	{
		ft_putchar_fd('%', 1);
		if (format.zero)
			nb_of_printed_chars += print_edges(format.width - 1, ' ');
		else
			nb_of_printed_chars += print_edges(format.width - 1, ' ');
	}
	else if (!format.dash)
	{
		if (format.zero)
			nb_of_printed_chars += print_edges(format.width - 1, '0');
		else
			nb_of_printed_chars += print_edges(format.width - 1, ' ');
		ft_putchar_fd('%', 1);
	}
	return (nb_of_printed_chars + 1);
}
