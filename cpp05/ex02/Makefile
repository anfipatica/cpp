NAME = bureaucrat

INC_DIR = ./inc
SRC_DIR = ./src/
OBJS_DIR = ./objs/

CXX = c++
CXXFLAGS =	-I$(INC_DIR) -Wextra -Wall -Werror
CXXFLAGS += -fsanitize=address
CXXFLAGS += -std=c++98

RM = rm -rf

SRCS = $(SRC_DIR)Bureaucrat.cpp $(SRC_DIR)AForm.cpp $(SRC_DIR)main.cpp \
		$(SRC_DIR)PresidentialPardonForm.cpp $(SRC_DIR)RobotomyRequestForm.cpp\
		$(SRC_DIR)ShrubberyCreationForm.cpp

OBJS = $(patsubst $(SRC_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))

GREEN = \033[0;32m
GRAY = \033[0;90m
STD = \033[0m

.PHONY: clean all fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)Compilation finished.$(STD)"

$(OBJS_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "$(GRAY)Compiling file  →   $< $(STD)"
	@mkdir -p $(OBJS_DIR)
	$(CXX) -c -MMD $(CXXFLAGS) -o $@ $<

clean:
	@$(RM) objs

fclean: clean
	@rm $(NAME)

re: fclean all

-include $(OBJS_DIR)/*.d
