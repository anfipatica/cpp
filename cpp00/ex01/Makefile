NAME = patata

INC_DIR = ./inc
OBJS_DIR = ./objs

CPP = c++
CPPFLAGS =	-I$(INC_DIR) -Wextra -Wall -Werror
CPPFLAGS += -std=c++98

RM = rm -rf

SRCS = main.cpp PhoneBook.cpp 

OBJS = $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))

GREEN = \033[0;32m
GRAY = \033[0;90m
STD = \033[0m

.PHONY: clean all fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)Compilation finished.$(STD)"

$(OBJS_DIR)/%.o: %.cpp
	@echo "$(GRAY)Compiling file  →   $< $(STD)"
	@mkdir -p $(OBJS_DIR)
	@$(CPP) -c -MMD $(CPPFLAGS) -o $@ $<
-include $(OBJS_DIR)/*.d

clean:
	@$(RM) objs

fclean: clean
	@rm $(NAME)

re: fclean all
