/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:13:32 by oshvorak          #+#    #+#             */
/*   Updated: 2018/01/30 16:28:46 by oshvorak         ###   ########.fr       */
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
	//int val;

	//ft_printf("blah %n blah\n", &val);

	//ft_printf("val = %d\n", val);

	//setlocale(LC_ALL, "en_US.UTF-8");

	//printf("SIZE %d\n", printf("%20.50f\n", 66.5));
	//printf("SIZE %d\n", printf("%n\n", 777));

	//printf("SIZE %d\n", printf("%20.9f\n", 5.999994));

	printf("SIZE %d\n", printf("%.4f\n", 1.89999999));
	printf("SIZE %d\n", ft_printf("%.4f\n", 1.89999999));

	printf("{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	ft_printf("{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);

	printf("{%f}{%F}\n", -1.42, -1.42);
	ft_printf("{%f}{%F}\n", -1.42, -1.42);

	printf("{%.3f}\n", 1.4739);
	ft_printf("{%.3f}\n", 1.4739);

	printf("{%f}{%F}\n", 1.42, 1.42);
	ft_printf("{%f}{%F}\n", 1.42, 1.42);

	//printf("SIZES %d\n", printf("stan a%Sb%sc%S", L"ÊM-M-^Q", "42", L"ÁM-^L´\n"));
	//printf("SIZEM %d\n", ft_printf("mymy a%Sb%sc%S", L"ÊM-M-^Q", "42", L"ÁM-^L´\n"));

	return (0);
}
