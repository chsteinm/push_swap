NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRCS = main_copy.c parse.c op.c op2.c op3.c sorte_stack.c radix.c special_sorte.c
OBJ = $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
SRCS_BONUS = checker_copy.c instruct_copy.c parse.c op.c \
			#get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_BONUS = $(addprefix $(BUILD_DIR)/,$(SRCS_BONUS:.c=.o))
BUILD_DIR = .build

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a -o $@

bonus: all $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) ./libft/libft.a -o $@

$(BUILD_DIR)/%.o: %.c Makefile
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

libft:
	make -C libft bonus

clean:
	make -C ./libft clean
	rm -rf $(BUILD_DIR)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean
	make

.PHONY: all clean fclean re bonus libft