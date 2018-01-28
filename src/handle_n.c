#include "../inc/ft_printf.h"

void	handle_n(t_spec *spec, int len, va_list ap)
{
	size_t *v;

	if (spec->size == none)
		v = va_arg(ap, int*);
	else if (spec->size == hh)
		v = va_arg(ap, signed char*);
	else if (spec->size == h)
		v = va_arg(ap, short int*);
	else if (spec->size == l)
		v = va_arg(ap, long int*);
	else if (spec->size == ll)
		v = va_arg(ap, long long int*);
	else if (spec->size == j)
		v = va_arg(ap, intmax_t*);
	else if (spec->size == z)
		v = va_arg(ap, size_t*);
	*v = len;
}
