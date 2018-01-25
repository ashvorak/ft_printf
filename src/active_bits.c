#include "../inc/ft_printf.h"

int active_bits(wchar_t value)
{
	int size = 21;
	int c = 1048576;
	while (size > 0)
	{
		if ((c & value) != 0)
			return (size);
		size--;
		c >>= 1;
	}
	return (size);
}
