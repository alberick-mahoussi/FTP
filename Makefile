##
## EPITECH PROJECT, 2023
## B-OOP-400-PAR-4-1-tekspice-alberick.mahoussi
## File description:
## Makefile
##

SRC 	=		$(shell echo source/*.c)

OBJ 	=		$(SRC:.c=.o)

NAME	=		myftp

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
