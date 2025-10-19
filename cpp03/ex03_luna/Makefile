#
# Name: Luna del Valle
# File: Makefile
# Created on: Wednesday Jul 30, 2025 14:32:43 CEST
#

########################

NAME		:=	bin

SRC			:=	src/main.cpp\
				src/ClapTrap.cpp\
				src/ScavTrap.cpp\
				src/FragTrap.cpp\
				src/DiamondTrap.cpp

OBJ			:=	$(SRC:%.cpp=obj/%.o)

CXX			:=	c++

CXXFLAGS	:=	-Wall -Wextra -Iinc -std=c++98 -Wshadow #-Werror

########################

all: $(NAME)

$(NAME): obj $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

obj:
	mkdir obj
	mkdir obj/src

obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

