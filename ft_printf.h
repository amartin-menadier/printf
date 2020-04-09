/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:21:52 by amartin-          #+#    #+#             */
/*   Updated: 2020/02/05 21:11:51 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct		s_format
{
	int	dash;
	int	zero;
	int	width;
	int	point;
	int	precision;
	int	advance;
}					t_format;

int					ft_printf(const char *instruction, ...);
int					simple_print(char c);
t_format			initialize_format(t_format format);
t_format			parse_format(const char *instr, t_format f, va_list arg);
t_format			fill_in_format(char c, t_format format, va_list args);
t_format			format_when_asterisk(t_format format, va_list args);
int					is_format(char c);
int					parse_type(char type, t_format format, va_list args);
int					fill_in_width(int width, char c);
int					print_edges(int width, char c);
int					print_char(t_format format, va_list args);
int					print_string(t_format format, va_list args);
char				*is_string(char *str, t_format format);
int					str_precision(char *str, int len, int precision, int print);
int					str_edges(int zero, int width, int print);
int					print_pointer(t_format format, va_list args);
char				*ulltoa_base(unsigned long long nb, char *base);
int					create_str(unsigned long long u, char *b, char *o, int l);
int					print_integer(t_format format, va_list args);
int					check_int_dash(t_format formt, int l, char *s, int d_or_i);
int					int_precision(t_format format, int len, int d_or_i);
int					int_edges(t_format format, int len, int d_or_i);
int					print_unsigned(t_format format, va_list args);
int					check_unsigned_dash(t_format format, int len, char *output);
int					unsigned_precision(int precision, int len);
int					unsigned_edges(t_format format, int len);
int					putnbr(unsigned int nb, char *base, char *str, int l);
char				*ft_itoa_base(unsigned int nbr, char *base);
int					hexa_edges(t_format format, int len);
int					hexa_precision(int precision, int len);
int					check_hexa_dash(t_format format, int len, char *str);
int					print_hexa(t_format format, va_list args, char *base);
int					print_percent(t_format format);
#endif
