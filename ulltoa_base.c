/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:48:47 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 21:14:21 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ulltoa_len(unsigned long long ull, int len_base)
{
	int	i;

	i = 0;
	while (ull > 0)
	{
		ull /= len_base;
		i++;
	}
	return (i);
}

int			create_str(unsigned long long u, char *base, char *outpt, int l_u)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (l_u == 0)
	{
		outpt[l_u] = base[u % len_base];
		return (0);
	}
	else
	{
		outpt[l_u] = base[u % len_base];
		return (create_str(u / len_base, base, outpt, --l_u));
	}
}

char		*ulltoa_base(unsigned long long ull, char *base)
{
	int		len_base;
	char	*output;
	int		len_ull;

	len_base = ft_strlen(base);
	len_ull = ulltoa_len(ull, len_base);
	if (!(output = malloc(sizeof(char) * len_ull + 1)))
		return (0);
	output[len_ull] = '\0';
	create_str(ull, base, output, len_ull - 1);
	return (output);
}
