/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:13:32 by oshvorak          #+#    #+#             */
/*   Updated: 2018/01/15 16:37:19 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <wchar.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
/*
	printf("The char: %c\n", 55);
	printf("The color: %s\n", "blue");
	printf("First number: %d\n", 12345);
	printf("Second number: %04d\n", 25);
	printf("Third number: %i\n", 1234);
	printf("Hexadecimal: %x\n", 255);
	printf("Octal: %o\n", 11);
	printf("Unsigned value: %u\n", 12345);
	printf("Just print the percentage sign %%\n");
*/
	//printf("------------------------------------\n");
/*
	ft_printf("The char: %c\n", 55);
	ft_printf("The color: %s\n", "blue");
	ft_printf("First number: %d\n", 12345);
	ft_printf("Second number: %04d\n", 25);
	ft_printf("Third number: %i\n", 1234);
	ft_printf("Hexadecimal: %x\n", 255);
	ft_printf("Octal: %o\n", 11);
	ft_printf("Unsigned value: %u\n", 12345);
 */

	//printf("%#o\n", 0);
	//ft_printf("%#o\n", 0);

	//printf("SIZE %d\n", printf("RES1: %010s %d\n", NULL, 1));
	//printf("SIZE %d\n", ft_printf("RES2: %010s %d\n", NULL, 1));
	//α⓯λα⓯λ

	//ft_putwchar(945);

	//printf("SIZE %d\n", printf("{%-30.9S}\n", L"ÊM-M-^QÊM-^XØ‰∏M"));
	//printf("SIZE %d\n", ft_printf("{%-30.9S}\n", L"ÊM-M-^QÊM-^XØ‰∏M"));

	printf("SIZE %d\n", printf("{%-30.9S}\n", NULL));
	printf("SIZE %d\n", ft_printf("{%-30.9S}\n", NULL));

	//printf("RES: %lld\n", -9223372036854775808);
	//ft_printf("RES: %lld\n", -9223372036854775808);

	//ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);

	//printf("@main_ftprintf: %33 .#00d\n", 256);
	//ft_printf("@main_ftprintf: %#33 .#00d\n", 256);

	//printf("SIZE %d\n", printf("%020zd\n", 5));
	//printf("SIZE %d\n", ft_printf("%020zd\n", 5));

	//printf("SIZE %d\n", printf("@moulitest: %05.o|\n", 0));
	//("SIZE %d\n", ft_printf("@moulitest: %05.o|\n", 0));

	//printf("SIZE %d\n", printf("@main_ftprintf: %33 .#00d\n", 256));
	//printf("SIZE %d\n", ft_printf("@main_ftprintf: %33 .#00d\n", 256));

	//printf("----------------------------------\n");
	//printf("SIZE %d\n", printf("%05d", -42));
	//printf("SIZE %d\n", ft_printf("%05d", -42));

	//printf("RES: %llhhd",  LLONG_MAX);
    //printf("RES: %-040.20o %s", 1111, "sss");

	return (0);
}
