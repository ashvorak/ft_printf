/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_qualifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 13:26:54 by oshvorak          #+#    #+#             */
/*   Updated: 2018/01/04 16:54:29 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		parse_flag(t_spec *spec, const char *p)
{
	if (*p == '-' && !spec->flags->minus)
		spec->flags->minus = TRUE;
	else if (*p == '+')
	{
		spec->flags->plus = TRUE;
		spec->flags->space = FALSE;
	}
	else if (*p == '0')
		spec->flags->zero = TRUE;
	else if (*p == ' ' && !spec->flags->plus)
		spec->flags->space = TRUE;
	else if (*p == '#')
		spec->flags->hash = TRUE;
}

static void		parse_width(t_spec *spec, const char *p)
{
	spec->width = ft_atoi(p);
}

static void		parse_accuracy(t_spec *spec, const char *p)
{
	spec->accuracy = ft_atoi(p);
}

static void		parse_size(t_spec *spec, const char *p)
{
	if (*p == 'h' && *(p + 1) != 'h' && spec->size == none)
		spec->size = h;
	else if (*p == 'h' && *(p + 1) == 'h' && spec->size < hh)
		spec->size = hh;
	else if (*p == 'l' && *(p + 1) != 'l' && spec->size < l)
		spec->size = l;
	else if (*p == 'l' && *(p + 1) == 'l' && spec->size < ll)
		spec->size = ll;
	else if (*p == 'j' && spec->size < j)
		spec->size = j;
	else if (*p == 'z')
		spec->size = z;
}

const char			*handle_qualifier(const char *p, t_spec *spec)
{
	while (!spec->type && *p)
		if (*p == '+' || *p == '-' || *p == '0' || *p == ' ' || *p == '#')
			parse_flag(spec, p++);
		else if (ft_isdigit(*p))
		{
			parse_width(spec, p);
			while (ft_isdigit(*p))
				p++;
		}
		else if (*p == '.')
		{
			parse_accuracy(spec, ++p);
			while (ft_isdigit(*p))
				p++;
		}
		else if (*p == 'h' || *p == 'l' || *p == 'j' || *p == 'z')
		{
			parse_size(spec, p);
			if (spec->size == hh || spec->size == ll)
				p++;
			p++;
		}
		else
			spec->type = *(p++);
	return (p);
}
