/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:45:17 by oshvorak          #+#    #+#             */
/*   Updated: 2018/01/29 20:34:42 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_spec	*spec_new(void)
{
	t_spec	*spec;

	if (!(spec = (t_spec*)malloc(sizeof(t_spec))))
		return (NULL);
	if (!(spec->flags = (t_flags*)malloc(sizeof(t_flags))))
		return (NULL);
	spec->flags->minus = FALSE;
	spec->flags->plus = FALSE;
	spec->flags->zero = FALSE;
	spec->flags->space = FALSE;
	spec->flags->hash = FALSE;
	spec->width = UNDEFINED;
	spec->accuracy = UNDEFINED;
	spec->size = none;
	spec->type = none;
	return (spec);
}

static t_spec	*fix(t_spec *spec)
{
	if (spec->type == 'p')
		spec->flags->hash = TRUE;
	else if (!is_type("oOxXp", spec->type))
		spec->flags->hash = FALSE;
	if (!is_type("dDifF", spec->type))
	{
		spec->flags->space = FALSE;
		spec->flags->plus = FALSE;
	}
	return (spec);
}

int				ft_printf(const char *format, ...)
{
	int		size;
	t_spec	*spec;
	va_list	ap;

	size = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			spec = spec_new();
			format = handle_qualifier(++format, spec, ap);
			size += handle_value(fix(spec), ap, size);
		}
		else
		{
			ft_putchar(*format++);
			size++;
		}
	}
	va_end(ap);
	return (size);
}
