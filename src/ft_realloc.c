#include "../inc/ft_printf.h"

char	*ft_realloc(char *str, int size)
{
	char *nstr;

	if (!(nstr = ft_strnew(size + 1)))
		return (NULL);
	if (str)
	{
		ft_memcpy(nstr, str, size);
		ft_strdel(&str);
	}
	return (nstr);
}
