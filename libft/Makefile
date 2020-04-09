# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartin- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 12:09:26 by amartin-          #+#    #+#              #
#    Updated: 2020/01/31 18:00:03 by amartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_strchr.c ft_split.c \
ft_calloc.c ft_strdup.c ft_strjoin.c \
ft_strlcat.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strlcpy.c ft_strnstr.c ft_strrchr.c \
ft_strtrim.c ft_tolower.c ft_toupper.c ft_substr.c \
ft_utoa.c \

OBJ = $(SRC:.c=.o)

INCLUDES=./

all : $(NAME)
$(NAME): $(SRC) libft.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re fclean clean all
