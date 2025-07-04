NAME = phonebook

INC_DIR = ./inc
OBJS_DIR = ./objs/
SRC_DIR = ./src/

CPP = c++
CPPFLAGS =	-I$(INC_DIR) -Wextra -Wall -Werror
CPPFLAGS += -std=c++98

RM = rm -rf

SRC =   $(SRC_DIR)main.cpp\
		$(SRC_DIR)Contact.cpp\
		$(SRC_DIR)PhoneBook.cpp\
		$(SRC_DIR)PhoneBook_search.cpp

OBJS = $(patsubst $(SRC_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRC))

GREEN = \033[0;32m
GRAY = \033[0;90m
STD = \033[0m

.PHONY: clean all fclean re

all:$(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)Compilation finished.$(STD)"

$(OBJS_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "$(GRAY)Compiling file  →   $< $(STD)"
	@mkdir -p $(OBJS_DIR)
	@$(CPP) -c -MMD $(CPPFLAGS) -o $@ $<
-include $(OBJS_DIR)/*.d

clean:
	@$(RM) objs

fclean: clean
	@rm $(NAME)

re: fclean all
