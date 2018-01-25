#include "../inc/ft_printf.h"

static int str_print(char *value, int len)
{
	int i;

	i = 0;
	while (i < len && *value)
	{
		ft_putchar(*value++);
		i++;
	}
	return (i);
}

static int parse_width(int len, t_spec *spec)
{
	int     size;
	char    sym;

	size = 0;
	sym = (spec->flags->zero) ? '0' : ' ';
	spec->width -= len;
	while (size < spec->width)
	{
		ft_putchar(sym);
		size++;
	}
	return (size);
}

int handle_str_subspec(char *value, t_spec *spec)
{
	int len;
	int size;

	size = 0;
	value = (!value) ? "(null)" : value;
	len = ft_strlen(value);
	if (spec->flags->minus)
	{
		if (spec->accuracy != UNDEFINED)
			len = (len > spec->accuracy) ? spec->accuracy : len;
		size += str_print(value, len);
		while (size < spec->width)
		{
			ft_putchar(' ');
			size++;
		}
	}
	else
	{
		if (spec->accuracy != UNDEFINED)
			len = (len > spec->accuracy) ? spec->accuracy : len;
		size += parse_width(len, spec);
		size += str_print(value, len);
	}
	return (size);
}