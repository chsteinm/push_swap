NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
PATH_SRCS = ./srcs/
SRCS = main.c parse.c op.c op2.c op3.c sorte_stack.c radix.c special_sorte.c fill_price.c r_and_p.c
OBJ = $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
SRCS_BONUS = checker_bonus.c instruct_bonus.c parse.c op.c get_next_line_bonus.c
OBJ_BONUS = $(addprefix $(BUILD_DIR)/,$(SRCS_BONUS:.c=.o))
BUILD_DIR = .build
LIBFT = ./includes/libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@
	@echo "\npush_swap is ready for use!\n"
	@echo 'tape for exemple : ARG="5 3 4"; ./push_swap $$ARG'"\n"

bonus: all $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $@
	@echo '\nchecker is ready for use too!'"\n"
	@echo 'tape for exemple : ARG="5 3 4"; ./push_swap $$ARG | ./checker $$ARG'"\n"

$(BUILD_DIR)/%.o: $(PATH_SRCS)%.c Makefile
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I ./includes

-include $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

$(LIBFT): FORCE
	@make --no-print-directory -C includes/libft bonus

clean:
	@make --no-print-directory -C ./includes/libft clean
	@rm -rf $(BUILD_DIR)

fclean: clean
	@make --no-print-directory -C ./includes/libft fclean
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean
	@make --no-print-directory

visu:
	@echo "replace ../../push_swap by ./push_swap\n"
	~/Documents/push_swap_git/push_swap_visualizer/build/bin/visualizer

FORCE:

.PHONY: all clean fclean re bonus FORCE