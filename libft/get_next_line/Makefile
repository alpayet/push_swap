.PHONY : all clean fclean re
SRC =  get_next_line.c
OBJ = $(SRC:.c=.o)
NAME = libftget_next_line.a
INC = get_next_line.h
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
