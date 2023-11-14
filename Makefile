NAME := libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar
ARFLAGS := -rcs
RM := rm -rf

INCLUDE = ft_printf.h

SRC_DIR := srcs
SRC = ft_printf ft_character

SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))

OBJ_DIR := obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH := ./libft
LIBFT = $(LIBFT_PATH)/libft.a

.PHONY: all bonus clean fclean re libft

all: $(LIBFT) $(NAME)

bonus: all

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

