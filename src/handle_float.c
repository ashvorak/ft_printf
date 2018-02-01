/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:27:25 by oshvorak          #+#    #+#             */
/*   Updated: 2018/01/30 13:31:51 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	parse_flags(char *value, t_spec *spec)
{
	if (*value == '-' || spec->flags->plus || spec->flags->space)
	{
		if (*value == '-')
			ft_putchar('-');
		else
			(spec->flags->plus) ? ft_putchar('+') : ft_putchar(' ');
		return (1);
	}
	return (0);
}

static int	parse_width(char *value, t_spec *spec, int len)
{
	int		size;
	int		end;
	char	sym;

	size = 0;
	sym = (spec->flags->zero) ? '0' : ' ';
	end = spec->width - len;
	if (spec->flags->zero)
		size += parse_flags(value, spec);
	if (*value == '-' || spec->flags->plus || spec->flags->space)
		end--;
	while (size < end)
	{
		ft_putchar(sym);
		size++;
	}
	if (!spec->flags->zero)
		size += parse_flags(value, spec);
	return (size);
}

int			handle_float(char *value, t_spec *spec)
{
	int len;
	int size;

	size = 0;
	len = *value != '-' ? ft_strlen(value) : ft_strlen(value) - 1;
	if (spec->flags->minus)
	{
		size += parse_flags(value, spec);
		(*value == '-') ? value++ : 0;
		write(1, value, len);
		while (size < spec->width - len)
		{
			ft_putchar(' ');
			size++;
		}
	}
	else
	{
		size += parse_width(value, spec, len);
		(*value == '-') ? value++ : 0;
		write(1, value, len);
	}
	return (size += ft_strlen(value));
}


