#include "../inc/ft_printf.h"

static int parse_int(t_spec *spec, va_list ap)
{
	int     size;
    char    *value;

    value = NULL;
    if (spec->size == none && spec->type != 'D')
            value = ft_itoa_int(va_arg(ap, int));
    else if (spec->type == 'D')
            value = ft_itoa_int(va_arg(ap, long int));
    else if (spec->size == hh)
        value = ft_itoa_int((signed char)va_arg(ap, int));
    else if (spec->size == h)
        value = ft_itoa_int((short int)va_arg(ap, int));
    else if (spec->size == l)
        value = ft_itoa_int(va_arg(ap, long int));
    else if (spec->size == ll)
        value = ft_itoa_int(va_arg(ap, long long int));
    else if (spec->size == j)
        value = ft_itoa_int(va_arg(ap, intmax_t));
    else if (spec->size == z)
        value = ft_itoa_int(va_arg(ap, size_t));
	size = handle_num_subspec(value, spec);
	(value) ? free(value) : 0;
    return (size);
}

static int parse_base(t_spec *spec, va_list ap)
{
	int     size;
    char    *value;

    value = NULL;
	if (spec->type == 'p')
		value = ft_itoa_base((size_t)va_arg(ap, void*), spec);
    else if (spec->size == none && is_type("oxXup", spec->type))
		value = ft_itoa_base(va_arg(ap, unsigned int), spec);
    else if (is_type("OU", spec->type))
		value = ft_itoa_base(va_arg(ap, unsigned long int), spec);
    else if (spec->size == hh)
        value = ft_itoa_base((unsigned char)va_arg(ap, unsigned int), spec);
    else if (spec->size == h)
        value = ft_itoa_base((unsigned short int)va_arg(ap, unsigned int), spec);
    else if (spec->size == l)
        value = ft_itoa_base(va_arg(ap, unsigned long int), spec);
    else if (spec->size == ll)
        value = ft_itoa_base(va_arg(ap, unsigned long long int), spec);
    else if (spec->size == j)
        value = ft_itoa_base(va_arg(ap, uintmax_t), spec);
    else if (spec->size == z)
        value = ft_itoa_base(va_arg(ap, size_t), spec);
	size = handle_num_subspec(value, spec);
	(value) ? free(value) : 0;
    return (size);
}

int handle_value(t_spec *spec, va_list ap)
{
	int	size;

	size = 0;
	if (spec->type == 'c' && spec->size != l)
		size = handle_char(va_arg(ap, int), spec);
	else if (spec->type == 'C' || (spec->type == 'c' && spec->size == l))
		size = handle_wchar(va_arg(ap, wint_t), spec);
	else if (spec->type == '%')
		size = handle_char('%', spec);
	else if (is_type("dDi", spec->type))
		size = parse_int(spec, ap);
	else if (is_type("oOxXuUp", spec->type))
		size = parse_base(spec, ap);
	else if (spec->type == 's' && spec->size != l)
		size = handle_str_subspec(va_arg(ap, char*), spec);
	else if (spec->type == 'S' || (spec->type == 's' && spec->size == l))
		size = handle_wstr(va_arg(ap, wchar_t*), spec);
	else if (spec->type)
		size = handle_char(spec->type, spec);
	free(spec->flags);
	free(spec);
    return (size);
}
