.PHONY : all lib_libft clean fclean re bonus
LIBFT_DIR = libft
SRC = main.c stack_fonctions.c execute_rules.c file_and_errors.c math_utils.c rules_params.c rules.c sort_algorithm.c
SRC_BONUS = main_bonus.c rules.c stack_fonctions.c file_and_errors.c utils_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = push_swap
NAME_BONUS = checker
INC = push_swap.h
INC_BONUS = push_swap_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L$(LIBFT_DIR) -lft
LFLAGS_BONUS = -L$(LIBFT_DIR) -lft -L$(LIBFT_DIR)/get_next_line -lftget_next_line
MAKE = @make --no-print-directory -j

all : lib_libft $(NAME)

bonus : lib_libft $(NAME_BONUS)

$(NAME) : $(OBJ) $(INC) $(LIBFT_DIR)/libft.a
	$(CC) -o $@ $(OBJ) $(LFLAGS)

$(NAME_BONUS) : $(OBJ_BONUS) $(INC_BONUS) $(LIBFT_DIR)/libft.a
	$(CC) -o $(NAME_BONUS) $(OBJ_BONUS) $(LFLAGS_BONUS)

%.o : %.c  Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

lib_libft :
	$(MAKE) -C $(LIBFT_DIR)

clean :
	$(MAKE) -C $(LIBFT_DIR)
	rm -f *.o

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all


