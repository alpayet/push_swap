.PHONY : all clean fclean re
SRC = printf.c ft_conversions.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
INC = ft_printf.h
LIBFT_DIR = ..
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $(OBJ) $(LIBFT_DIR)/*.o

%.o : %.c $(INC) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
