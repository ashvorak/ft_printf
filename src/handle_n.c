#include "../inc/ft_printf.h"

void	handle_n(t_spec *spec, int len, va_list ap)
{
	size_t *uv;
	ssize_t *sv;

	sv = NULL;
	uv = NULL;
	if (spec->size == none)
		sv = (ssize_t*)va_arg(ap, int*);
	else if (spec->size == hh)
		sv = (ssize_t*)va_arg(ap, signed char*);
	else if (spec->size == h)
		sv = (ssize_t*)va_arg(ap, short int*);
	else if (spec->size == l)
		sv = va_arg(ap, long int*);
	else if (spec->size == ll)
		uv = (size_t*)va_arg(ap, long long int*);
	else if (spec->size == j)
		uv = (size_t*)va_arg(ap, intmax_t*);
	else if (spec->size == z)
		uv = va_arg(ap, size_t*);
	if (sv)
		*sv = len;
	else
		*uv = len;
}
