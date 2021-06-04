# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 11:30:38 by aaparici          #+#    #+#              #
#    Updated: 2021/02/18 20:18:48 by aaparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME ?= libft.a

SRC := \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_calloc.c \
	ft_split.c \
	ft_strchr.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putnbr_fd.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_atoi.c \
	ft_strnstr.c \
	
SRC_BONUS := \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \

OBJ := $(SRC:.c=.o)
OBJ_BONUS := $(SRC_BONUS:.c=.o)

CFLAGS ?= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) 
	ar rc $@ $^
	ranlib $@

bonus: $(OBJ_BONUS) $(OBJ)
	ar ru $(NAME) $^
	ranlib $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)\
	
fclean: clean
	$(RM) $(NAME)

re: fclean all bonus

.PHONY: all clean fclean re bonus
