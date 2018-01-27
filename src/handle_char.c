/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:27:19 by oshvorak          #+#    #+#             */
/*   Updated: 2018/01/27 16:10:50 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	handle_char(char c, t_spec *spec)
{
	int		size;
	char	sym;

	size = 0;
	if (spec->flags->minus)
	{
		ft_putchar(c);
		while (++size < spec->width)
			ft_putchar(' ');
	}
	else
	{
		sym = (spec->flags->zero) ? '0' : ' ';
		while (++size < spec->width)
			ft_putchar(sym);
		ft_putchar(c);
	}
	return (size);
}
