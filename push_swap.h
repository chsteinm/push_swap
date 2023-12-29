#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //a supprimer
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

int     parse(t_list **stack_a, char **args);
void    error();
int		is_sorte(t_list *stack_a);
void    swap(t_list **stack);
void	push(t_list **a, t_list **b);
void	rotate(t_list **stack);
void	r_rotate(t_list **stack);

#endif