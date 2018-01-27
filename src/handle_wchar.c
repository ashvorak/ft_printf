/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:27:50 by oshvorak          #+#    #+#             */
/*   Updated: 2018/01/27 15:27:51 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	handle_wchar(wchar_t c, t_spec *spec)
{
	int		size;
	int		bits;
	char	sym;

	size = 0;
	bits = active_bits(c);
	if (spec->flags->minus)
	{
		size += size_char(bits);
		ft_putwchar(c, bits);
		while (size < spec->width)
		{
			ft_putchar(' ');
			size++;
		}
	}
	else
	{
		sym = (spec->flags->zero) ? '0' : ' ';
		size += size_char(bits);
		while (size < spec->width)
		{
			ft_putchar(sym);
			size++;
		}
		ft_putwchar(c, bits);
	}
	return (size);
}
