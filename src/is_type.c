#include "../inc/ft_printf.h"

int is_type(char *types, char type)
{
	while (*types)
	{
		if (*types == type)
			return (TRUE);
		types++;
	}
	return (FALSE);
}
