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
	int val;

	ft_printf("blah %n blah\n", &val);

	ft_printf("val = %d\n", val);

	//setlocale(LC_ALL, "en_US.UTF-8");

	//printf("SIZE %d\n", printf("%20.50f\n", 66.5));
	//printf("SIZE %d\n", printf("%n\n", 777));
	//printf("SIZE %d\n", ft_printf("%020hhx\n", 777));

	return (0);
}
