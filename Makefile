CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c format.c type.c typeisc_char.c typeiss_string.c typeisp_pointer.c ulltoa_base.c typeisdi_integer.c typeisu_unsigned.c typeisx_hexadecimal.c itoa_base.c typeispercent.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		cd libft && $(MAKE)
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS)
all : $(NAME)

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./libft
fclean : clean
		rm -f $(NAME)
		rm -f libft.a
		$(MAKE) fclean -C ./libft
re : fclean all

%.o: %.c
	$(CC) $(FLAGS) -I ft_printf.h -c $<  -o $(<:.c=.o)
