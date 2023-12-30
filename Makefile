NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
SRCS = main.c parse.c op.c sorte_stack.c
OBJ = $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
SRCS_BONUS =
OBJ_BONUS = $(SRCS_BONUS:.c=.o)
BUILD_DIR = .build

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -MMD -MP $^ ./libft/libft.a -o $@

bonus: $(NAME) $(OBJ_BONUS)
	@if [ "$$(find $(OBJ_BONUS) -newer "$(NAME)" -print -quit)" ]; then \
		ar rcs $(NAME) $^; \
	else \
		echo "make: Nothing to be done for 'bonus'."; \
	fi

$(BUILD_DIR)/%.o: %.c Makefile libft
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

libft:
	make -C libft bonus

clean:
	make -C ./libft clean
	rm -f *.o *.d

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re : fclean
	make

.PHONY: all clean fclean re bonus libft