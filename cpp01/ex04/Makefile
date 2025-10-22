NAME = new_sed

SRC_DIR = ./src/
OBJS_DIR = ./objs/

CXX = c++
CXXFLAGS =	-Wextra -Wall -Werror
CXXFLAGS += -fsanitize=address
CXXFLAGS += -std=c++98

RM = rm -rf

SRCS = $(SRC_DIR)main.cpp 

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
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	@$(RM) objs

fclean: clean
	@rm $(NAME)

re: fclean all
