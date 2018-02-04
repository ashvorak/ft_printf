/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:13:32 by oshvorak          #+#    #+#             */
/*   Updated: 2018/02/04 16:55:35 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <wchar.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <float.h>
#include <fcntl.h>

int main(void)
{
	//int fd1;
	//int fd2;

	//fd1 = open("f1", O_WRONLY);
	//fd2 = open("f2", O_WRONLY);

	//printf("%d\n", fd2);

	//ft_printf("{fpurple}%s\n", "abcdefg");

	printf("SIZE %d\n", printf("{%15x}\n", 123));
	printf("SIZE %d\n", ft_printf("{%15x}\n", 123));

	//printf("SIZE %d\n", printf("{%15d}\n", 123));
	//printf("SIZE %d\n", ft_printf("{%15d}\n", 123));

	//close(fd1);
	//close(fd2);

	//int val;

	//ft_printf("blah %n blah\n", &val);

	//ft_printf("val = %d\n", val);

	//setlocale(LC_ALL, "en_US.UTF-8");
/*
	printf("SIZE %d\n", printf("%20.50f\n", 66.5));
	printf("SIZE %d\n", ft_printf("%20.50f\n", 66.5));

	printf("SIZE %d\n", printf("%.5f\n", 1.89499999));
	printf("SIZE %d\n", ft_printf("%.5f\n", 1.89499999));

	printf("{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	ft_printf("{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);

	printf("{%f}{%F}\n", -0.42, -1.42);
	ft_printf("{%f}{%F}\n", -0.42, -1.42);

	printf("{%20.F}\n", 667.5);
	ft_printf("{%20.F}\n", 667.5);

	printf("{%f}{%F}\n", 1.42, 1.42);
	ft_printf("{%f}{%F}\n", 1.42, 1.42);
 
	printf("{%.7f}{%F}\n", 666666666666.666666, 1.42);
	ft_printf("{%.7f}{%F}\n", 666666666666.666666, 1.42);

	printf("{%f}{%F}\n", 0.0, -0.0);
	ft_printf("{%f}{%F}\n", 0.0, -0.0);

	//printf("{%d}{%x}\n", 123, 456);
	//ft_printf("{%d}{%x}\n", 123, 456);
*/
	//printf("SIZES %d\n", printf("stan a%Sb%sc%S", L"ÊM-M-^Q", "42", L"ÁM-^L´\n"));
	//printf("SIZEM %d\n", ft_printf("mymy a%Sb%sc%S", L"ÊM-M-^Q", "42", L"ÁM-^L´\n"));

	return (0);
}
