CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
UTILS_DIR = $(SRC_DIR)/utils
TAB_DIR = $(UTILS_DIR)/tab
ERRORS_DIR = $(UTILS_DIR)/errors
INC_DIR = includes
LIBFT_DIR = lib/libft

SRC_FILES = $(SRC_DIR)/push_swap.c \
			$(TAB_DIR)/push.c \
			$(TAB_DIR)/swap.c \
			$(TAB_DIR)/rotate.c \
			$(TAB_DIR)/reverse_rotate.c \
			$(TAB_DIR)/utils.c \
			$(ERRORS_DIR)/main.c \
			$(SRC_DIR)/utils/main.c \
			$(UTILS_DIR)/algorithm/sort.c \
			$(UTILS_DIR)/algorithm/push_numbers.c \
			$(UTILS_DIR)/algorithm/get.c
OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = push_swap

LIBFT = $(LIBFT_DIR)/libft.a

INC = -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(OBJ_FILES) $(LIBFT) -o $(NAME)

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
