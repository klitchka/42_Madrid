# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 17:51:05 by aaparici          #+#    #+#              #
#    Updated: 2021/05/23 10:27:01 by aaparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME ?= libftprintf.a

SRC = ft_printf.c c_cdisu.c c_px.c mod.c c_fmt.c

OBJ	= $(SRC:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

$(NAME):	$(OBJ)
			cd libft && $(MAKE)
			cp libft/libft.a $@
			ar rc  $@ $^
			ranlib $@

all:		$(NAME)

clean:
			$(RM) $(OBJ) $(OBJ_B)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			$(RM) libft.a
			$(MAKE) fclean -C ./libft
	
re:			fclean all

test:
			$(CC) -o test test.c libftprintf.a

.PHONY: all clean fclean re
