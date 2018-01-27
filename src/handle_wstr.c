/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:27:59 by oshvorak          #+#    #+#             */
/*   Updated: 2018/01/27 15:28:13 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	str_print(wchar_t *value, t_spec *spec)
{
	int i;
	int j;
	int bits;

	i = 0;
	while (*value)
	{
		bits = active_bits(*value);
		j = size_char(bits);
		if (i + j <= spec->accuracy || spec->accuracy == UNDEFINED)
		{
			ft_putwchar(*value++, bits);
			i += j;
		}
		else
			break ;
	}
	return (i);
}

static int	parse_width(wchar_t *value, t_spec *spec)
{
	int		i;
	int		size;
	char	sym;

	i = 0;
	size = 0;
	sym = (spec->flags->zero) ? '0' : ' ';
	while (*value)
	{
		if (i + size_char(active_bits(*value)) <= spec->accuracy || spec->accuracy == UNDEFINED)
			i += size_char(active_bits(*value++));
		else
			break ;
	}
	while (size < spec->width - i)
	{
		ft_putchar(sym);
		size++;
	}
	return (size);
}

int			handle_wstr(wchar_t *value, t_spec *spec)
{
	int size;

	size = 0;
	value = (value) ? value : L"(null)";
	if (spec->flags->minus)
	{
		size += str_print(value, spec);
		while (size < spec->width)
		{
			ft_putchar(' ');
			size++;
		}
	}
	else
	{
		size += parse_width(value, spec);
		size += str_print(value, spec);
	}
	return (size);
}
