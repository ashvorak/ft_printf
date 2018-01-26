#include "../inc/ft_printf.h"

static int parse_flags(char *value, t_spec *spec)
{
	if (*value == '-' || spec->flags->plus || spec->flags->space)
	{
		if (*value == '-')
			ft_putchar('-');
		else
			(spec->flags->plus) ? ft_putchar('+') : ft_putchar(' ');
		return (1);
	}
	else if (spec->flags->hash || spec->type == 'p')
	{
		if (is_type("oO", spec->type))
			if (*value != '0' || spec->accuracy == 0)
			{
				ft_putchar('0');
				return (1);
			}
		else if (is_type("xXp", spec->type))
		{
			if (*value != '0' || spec->type == 'p')
			{
				(spec->type == 'X') ? ft_putstr("0X") : ft_putstr("0x");
				return (2);
			}
		}
	}
	return (0);
}

static int parse_accuracy(int len, t_spec *spec, char *value)
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

static int parse_width(char *value, t_spec *spec, int len)
{
	int     size;
	int     end;
	char    sym;

	size = (spec->flags->zero && spec->accuracy < 0) ? parse_flags(value, spec) : 0;
	sym = (spec->flags->zero && spec->accuracy < 0) ? '0' : ' ';
	len = spec->accuracy > len ? spec->accuracy : len;
	end = spec->width - len;
	if (*value == '0' && spec->accuracy == 0)
		end++;
	if (size == 0 && *value != '0' && (spec->accuracy == 0 || spec->accuracy == UNDEFINED) && spec->flags->hash && is_type("oO", spec->type))
		end--;
	else if (size == 0 && spec->flags->hash && (*value != '0' || spec->type == 'p') && (is_type("xXp", spec->type)))
		end -= 2;
	else if ((spec->flags->plus || spec->flags->space || *value == '-') && (!spec->flags->zero || spec->accuracy >= 0))
		end--;
	while (size < end)
	{
		ft_putchar(sym);
		size++;
	}
	size += (!spec->flags->zero || spec->accuracy >= 0) ? parse_flags(value, spec) : 0;
	return (size);
}

int handle_num_subspec(char *value, t_spec *spec)
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
		(*value == '0' && spec->accuracy == 0) ? 0 : ft_putstr(value);
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
		(*value == '0' && spec->accuracy == 0) ? size-- : ft_putstr(value);
	}
	size += ft_strlen(value);
	return (size);
}
