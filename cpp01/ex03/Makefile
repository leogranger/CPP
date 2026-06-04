NAME = violence

# Directories
INCDIR = includes
SRCDIR = srcs
OBJDIR = objs

SRCS_MAIN = main.cpp

SRCS_FULL = $(addprefix $(SRCDIR)/,\
	Weapon.cpp HumanA.cpp HumanB.cpp)

# Source files (structure pour expansion future)
SRCS = $(SRCS_MAIN) $(SRCS_FULL)
INCLUDES = -I$(INCDIR)

# Object files
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

# Compiler and flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Colors
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

# Rules
all: $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "$(CYAN)Compiling $(notdir $<)...$(RESET)\r"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(GREEN)✓ Compiled $(notdir $<)   $(RESET)\n"

$(NAME): $(OBJS)
	@echo "$(YELLOW)🔗 Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(CYAN)✓ Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)✓ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re