#include "../inc/ft_printf.h"

char	*convert_float(double v_double, t_spec *spec)
{
	int		i;
	ssize_t 	v_int;
	double 	acc;
	char 	*v;

	i = 0;
	acc = 1;
	(spec->accuracy == UNDEFINED) ? spec->accuracy = 6 : 0;
	if (spec->accuracy != 0)
	{
		while (i < spec->accuracy)
		{
			acc /= 10;
			i++;
		}
		if (v_double > 0)
			v_double += acc;
		else
			v_double -= acc;
	}
	v_int = (ssize_t)v_double;
	v = convert_int(v_int);
	if (spec->accuracy != 0)
	{
		v = ft_realloc(v, ft_strlen(v));
		v = ft_strcat(v, ".");
	}
	i = 0;
	v_double = (v_double < 0) ? -v_double : v_double;
	v_int = (v_int < 0) ? -v_int : v_int;
	v_double -= (double)v_int;
	while (i < spec->accuracy)
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
