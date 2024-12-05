# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = srcs
UTILS_DIR = $(SRC_DIR)/utils
TAB_DIR = $(UTILS_DIR)/tab
ERRORS_DIR = $(UTILS_DIR)/errors
INC_DIR = includes
LIBFT_DIR = lib/libft

# Source files
SRC_FILES = $(SRC_DIR)/push_swap.c \
			$(TAB_DIR)/push.c \
			$(TAB_DIR)/swap.c \
			$(TAB_DIR)/rotate.c \
			$(TAB_DIR)/reverse_rotate.c \
			$(TAB_DIR)/utils.c \
			$(ERRORS_DIR)/main.c \
			$(UTILS_DIR)/algorithm/sort.c \
			$(UTILS_DIR)/algorithm/utils.c \
			$(UTILS_DIR)/algorithm/stack.c \
			$(UTILS_DIR)/algorithm/chunk.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Name of the executable
NAME = push_swap

# Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Include paths
INC = -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rule to compile the executable
$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LIBFT) -o $(NAME)

# Rule to compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
