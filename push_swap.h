#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

# include <stdio.h> //a supprimer

int     parse(t_list **stack_a, char **args);
void    error(t_list **stack_a);
int		is_sorte(t_list *stack_a);
void    swap(t_list **stack);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	push(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	rotate(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	r_rotate(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	sorte_stack(t_list **stack_a, t_list **stack_b, int size);
void	sorte_3(t_list **stack_a);
void	radix(t_list **stack_a, t_list **stack_b, int size);


void	instruct(t_list **stack_a, t_list **stack_b);

#endif