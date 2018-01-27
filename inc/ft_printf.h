/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:19:10 by oshvorak          #+#    #+#             */
/*   Updated: 2018/01/17 14:14:23 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "../lib/libft.h"

# define TRUE  1
# define FALSE 0
# define UNDEFINED -1

typedef struct 	s_flags
{
	int 	minus;
	int 	plus;
	int 	zero;
	int 	space;
	int 	hash;
}				t_flags;

typedef enum s_size
{
	none,
    h,
    hh,
    l,
    ll,
    j,
    z
} 			t_size;

typedef struct	s_spec
{
	t_flags *flags;
	int		width;
	int		accuracy;
	t_size 	size;
	char 	type;
}				t_spec;

int				ft_printf(const char *format, ...);
const char		*handle_qualifier(const char *p, t_spec *spec, va_list ap);
char            *ft_itoa_int(ssize_t value);
char            *ft_itoa_base(size_t value, t_spec *spec);
int				handle_value(t_spec *spec, va_list ap);
int             handle_char(char c, t_spec *spec);
int             handle_wchar(wchar_t c, t_spec *spec);
int				handle_num_subspec(char *value, t_spec *spec);
int             handle_str_subspec(char *value, t_spec *spec);
int             handle_wstr(wchar_t *value, t_spec *spec);
void            ft_putwchar(wchar_t value, int bits);
int             active_bits(wchar_t value);
int             size_char(int bits);
int             is_type(char *types, char type);

#endif
