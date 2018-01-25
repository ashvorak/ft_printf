# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 15:12:57 by oshvorak          #+#    #+#              #
#    Updated: 2018/01/23 15:13:01 by oshvorak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

MAKELIB = make -C lib

MAKESRC = make -C src

all:
	$(MAKELIB)
	$(MAKESRC)
	@ar x lib/libft.a 
	@ar x src/printf.a
	@ar cr $(NAME) *.o
	rm -f *.o

clean:
	$(MAKELIB) clean
	$(MAKESRC) clean

fclean:
	$(MAKELIB) fclean
	$(MAKESRC) fclean
	rm -f $(NAME)

re: fclean all
