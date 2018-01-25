#include "../inc/ft_printf.h"

int handle_char(char c, t_spec *spec)
{
	int     size;
	char    sym;

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

