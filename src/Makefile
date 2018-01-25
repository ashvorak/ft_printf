#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshvorak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:30:49 by oshvorak          #+#    #+#              #
#    Updated: 2017/10/25 13:01:56 by oshvorak         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = printf.a

SRC = 	ft_itoa_base.c ft_itoa_int.c ft_printf.c handle_num_subspec.c handle_qualifier.c handle_str_subspec.c handle_value.c handle_char.c is_type.c size_char.c active_bits.c ft_putwchar.c handle_wstr.c handle_wchar.c

OSRC = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)
	
$(NAME): $(OSRC)
	ar cr $(NAME) $(OSRC)
	ranlib $(NAME)

%.o : %.c
	gcc -c -Wall -Wextra -Werror $<

clean:
	rm -f $(OSRC) *.gch

fclean: clean
	rm -f $(NAME)

re: fclean all
