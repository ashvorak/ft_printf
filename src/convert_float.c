#include "../inc/ft_printf.h"

static double fix_accuracy(double v_double, t_spec *spec)
{
	int		i;
	ssize_t 	tmp_i;
	double	tmp_d;
	double 	acc;

	i = 0;
	acc = 1;
	tmp_d = v_double;
	tmp_i = (ssize_t)tmp_d;
	tmp_d -= (double)tmp_i;
	while (i <= spec->accuracy)
	{
		acc /= 10;
		tmp_d *= 10;
		tmp_i = (ssize_t)tmp_d;
		tmp_d -= (ssize_t)tmp_d;
		i++;
	}
	tmp_i = (tmp_i < 0) ? -tmp_i : tmp_i;
	if (tmp_i >= 5)
	{
		acc *= 10;
		v_double += (v_double > 0) ? acc : -acc;
	}
	return (v_double);
}

char	*convert_float(double v_double, t_spec *spec)
{
	int		i;
	ssize_t v_int;
	char 	*v;

	i = 0;
	(spec->accuracy == UNDEFINED) ? spec->accuracy = 6 : 0;
	v_double = fix_accuracy(v_double, spec);
	v_int = (ssize_t)v_double;
	v = convert_int(v_int);
	if (spec->accuracy != 0)
	{
		v = ft_realloc(v, ft_strlen(v));
		v = ft_strcat(v, ".");
	}
	v_double = (v_double < 0) ? -v_double : v_double;
	v_int = (v_int < 0) ? -v_int : v_int;
	v_double -= (double)v_int;
	while (i <= spec->accuracy)
	{
		v_double *= 10;
		v_int = (ssize_t)v_double;
		v_double -= (ssize_t)v_double;
		v = ft_realloc(v, ft_strlen(v));
		v = ft_strcat(v, ft_itoa(v_int));
		i++;
	}
	return (v);
}
