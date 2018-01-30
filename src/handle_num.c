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
	else if (spec->flags->hash)
	{
		if (is_type("oO", spec->type))
			if (*value != '0' || spec->accuracy == 0)
			{
				ft_putchar('0');
				return (1);
			}
		if (is_type("xXp", spec->type))
			if (*value != '0' || spec->type == 'p')
			{
				(spec->type == 'X') ? ft_putstr("0X") : ft_putstr("0x");
				return (2);
			}
	}
	return (0);
}

static int	parse_accuracy(int len, t_spec *spec, char *value)
{
	int size;
	int end;

	size = 0;
	end = spec->accuracy - len;
	if (spec->flags->hash && (is_type("oO", spec->type)) && *value != '0')
		end--;
	while (size < end)
	{
		ft_putchar('0');
		size++;
	}
	return (size);
}

static int	take_end(char *value, t_spec *spec, int size, int end)
{
	if (*value == '0' && spec->accuracy == 0)
		end++;
	if (size == 0 && *value != '0' && is_type("oO", spec->type) && \
	spec->flags->hash && (spec->accuracy == 0 || spec->accuracy == UNDEFINED))
		end--;
	else if (size == 0 && spec->flags->hash && \
	(*value != '0' || spec->type == 'p') && (is_type("xXp", spec->type)))
		end -= 2;
	else if ((spec->flags->plus || spec->flags->space || *value == '-')\
	&& (!spec->flags->zero || spec->accuracy >= 0))
		end--;
	return (end);
}

static int	parse_width(char *value, t_spec *spec, int len)
{
	int		size;
	int		end;
	char	sym;

	size = 0;
	if (spec->flags->zero && spec->accuracy < 0)
		size = parse_flags(value, spec);
	sym = (spec->flags->zero && spec->accuracy < 0) ? '0' : ' ';
	len = spec->accuracy > len ? spec->accuracy : len;
	end = take_end(value, spec, size, spec->width - len);
	while (size < end)
	{
		ft_putchar(sym);
		size++;
	}
	if (!spec->flags->zero || spec->accuracy >= 0)
		size += parse_flags(value, spec);
	return (size);
}

int			handle_num(char *value, t_spec *spec)
{
	int len;
	int size;

	size = 0;
	len = *value != '-' ? ft_strlen(value) : ft_strlen(value) - 1;
	if (spec->flags->minus)
	{
		size += parse_flags(value, spec);
		size += parse_accuracy(len, spec, value);
		(*value == '-') ? value++ : 0;
		(*value == '0' && spec->accuracy == 0) ? 0 : write(1, value, len);
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
		size += parse_accuracy(len, spec, value);
		(*value == '0' && spec->accuracy == 0) ? size-- : write(1, value, len);
	}
	return (size += ft_strlen(value));
}
