##
## EPITECH PROJECT, 2022
## B-OOP-400-COT-4-1-arcade-heritier.daga
## File description:
## Makefile
##

SRC = lib_sfml.cpp\

OBJ	=	$(SRC:.cpp=.o)

NAME =	../librairies/sfml_lib.so

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ -c -fPIC $(SRC)
		g++ -o $(NAME) -shared $(OBJ) -fPIC -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -fno-gnu-unique
		rm -f lib_sfml.o

clean:
	rm -rf lib_sfml.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re