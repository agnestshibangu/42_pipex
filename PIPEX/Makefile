# Program name
NAME	= pipex

# Compiler options
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

# printf 
PRINTF_DIR := ./my_printf/
PRINTF_SRCS := $(wildcard $(PRINTF_DIR)*.c)
PRINTF_OBJS := $(patsubst $(PRINTF_DIR)%.c, $(PRINTF_DIR)%.o, $(PRINTF_SRCS))


# program files
# SRC		= 	$(PRINTF_OBJS) \

SRC		= 	utils.c \
			main.c \
	

OBJ		= $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

#printf
$(PRINTF_OBJS): $(PRINTF_SRCS)
	@make -C $(PRINTF_DIR)

# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m
BLUE = \033[94m

# Compiling PUSH_SWAP
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -g
	@echo "  "  
	@echo "👾👾👾👾👾👾👾👾👾👾👾👾👾👾" 
	@echo "  ^    ^    ^    ^    ^  "  
	@echo "👾 /P\  /I\  /P\  /E\  /X\ 👾" 
	@echo "  <___><___><___><___><___>  "
	@echo "👾👾👾👾👾👾👾👾👾👾👾👾👾👾"
	@echo "  " 



clean:
	@echo "🧹 ALL FILES HAVE BEEN DELETED 🧹"
	@rm -rf $(OBJ)


fclean: clean
	@echo "🧹 ALL FILES HAVE BEEN DELETED 🧹"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus