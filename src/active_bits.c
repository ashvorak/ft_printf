#include "../inc/ft_printf.h"

int active_bits(wchar_t value)
{
	int ret = 0;
	int size = 0;
	unsigned int c = 1;

	while (size < 32)
	{
		size++;
		if ((c & value) != 0)
			ret = size;
		c <<= 1;
	}
	return (ret);
}
