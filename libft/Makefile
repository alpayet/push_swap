.PHONY : all libs clean fclean re
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_putchar_fd.c ft_memset.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJ = $(SRC:.c=.o)
NAME = libft.a
INC = libft.h
PRINTF_DIR = printf
GNL_DIR = get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = @make --no-print-directory -j

all : $(NAME) libs

$(NAME) : $(OBJ)
	ar rcs $@ $^

%.o : %.c $(INC) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

libs :
	$(MAKE) -C $(PRINTF_DIR)
	$(MAKE) -C $(GNL_DIR)

clean :
	rm -f *.o
	$(MAKE) clean -C $(PRINTF_DIR)
	$(MAKE) clean -C $(GNL_DIR)

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(MAKE) fclean -C $(GNL_DIR)

re : fclean all