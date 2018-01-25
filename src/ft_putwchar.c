#include "../inc/ft_printf.h"

static void parse_2bytes(unsigned int v, unsigned int mask1)
{
	unsigned char octet;
	unsigned char o1;
	unsigned char o2;

	o2 = (v << 26) >> 26; // Восстановление первых 6 бит 110xxxxx 10(xxxxxx)
	o1 = ((v >> 6) << 27) >> 27; // Восстановление последних 5 бит 110(xxxxx) 10xxxxxx

	octet = (mask1 >> 8) | o1; // Применение первой битовой маски ко первому байту
	write(1, &octet, 1);
	octet = ((mask1 << 24) >> 24) | o2; // Применение второй битовой маски ко второму байту
	write(1, &octet, 1);
}

static void parse_3bytes(unsigned int v, unsigned int mask2)
{
	unsigned char octet;
	unsigned char o1;
	unsigned char o2;
	unsigned char o3;

	o3 = (v << 26) >> 26; // Восстановление первых 6 бит 1110xxxx 10xxxxxx 10(xxxxxx)
	o2 = ((v >> 6) << 26) >> 26; // Восстановление вторых 6 бит 1110xxxx 10(xxxxxx) 10xxxxxx
	o1 = ((v >> 12) << 28) >> 28; // Восстановление последних 4 бит 1110(xxxx) 10xxxxxx 10xxxxxx

	octet = (mask2 >> 16) | o1; // Применение первой битовой маски ко первому байту
	write(1, &octet, 1);
	octet = ((mask2 << 16) >> 24) | o2; // Применение второй битовой маски ко второму байту
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
	write(1, &octet, 1);
}

static void parse_4bytes(unsigned int v, unsigned int mask3)
{
	unsigned char octet;
	unsigned char o1;
	unsigned char o2;
	unsigned char o3;
	unsigned char o4;

	o4 = (v << 26) >> 26; // Восстановление первых 6 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
	o3 = ((v >> 6) << 26) >> 26; // Восстановление вторых 6 бит 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
	o2 = ((v >> 12) << 26) >> 26;  // Восстановление третьих 6 бит bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
	o1 = ((v >> 18) << 29) >> 29; // Восстановление последних 3 бита 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx

	octet = (mask3 >> 24) | o1; // Применение бит первого байта на первый байт маски
	write(1, &octet, 1);
	octet = ((mask3 << 8) >> 24) | o2; // Применение второй битовой маски ко второму байту
	write(1, &octet, 1);
	octet = ((mask3 << 16) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
	write(1, &octet, 1);
	octet = ((mask3 << 24) >> 24) | o4; // Применение последней битовой маски ко последнему байту
	write(1, &octet, 1);
}

void ft_putwchar(wchar_t value, int bits)
{
	unsigned int mask1;
	unsigned int mask2;
	unsigned int mask3;
	unsigned char octet;
	unsigned int v;

	v = value;
	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	octet = 0;
	if (bits <= 7)
		ft_putchar((char)value);
	else if (bits <= 11)
		parse_2bytes(v, mask1);
	else if (bits <= 16)
		parse_3bytes(v, mask2);
	else
		parse_4bytes(v, mask3);
}