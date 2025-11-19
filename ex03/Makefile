# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 23:33:35 by lomont            #+#    #+#              #
#    Updated: 2025/11/19 01:28:34 by lomont           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = InterfaceAndRecap

C++ = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

RM = rm -f

SRC = ./main.cpp \
		./AMateria.cpp \
		./Character.cpp \
		./Cure.cpp \
		./Ice.cpp \
		./ICharacter.cpp \
		./IMateriaSource.cpp \
		./MateriaSource.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(C++) $(CFLAGS) -c $< -o $@

make: make all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
