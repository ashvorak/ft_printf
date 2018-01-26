#include "../inc/ft_printf.h"

int active_bits(wchar_t value)
{
	int size = 32;
	unsigned int c = 2147483648;
	while (size > 0)
	{
		if ((c & value) != 0)
			return (size);
		size--;
		c >>= 1;
	}
	return (size);
}
