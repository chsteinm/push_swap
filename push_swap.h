/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:05:40 by chrstein          #+#    #+#             */
/*   Updated: 2024/01/17 18:06:23 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

#include <stdio.h>

typedef struct s_strct
{
	int		size_a;
	int		size_b;
}	t_strct;

int		parse(t_list **stack_a, char **args);
void	error(t_list **stack_a);
int		is_sorte(t_list *stack_a);
void	swap(t_list **stack);
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
void	radix(t_list **stack_a, t_list **stack_b, const char *base);
void	special_sorte(t_list **stack_a, t_list **stack_b, int size);
void	fill_price(t_list **stack_a, t_list **stack_b, int size_b);
void	put_min_on_top(t_list **stack_a, int size_a);
void	r_and_p(t_list **stack_a, t_list **stack_b, int size_a, int size_b);


// for bonus :

void	instruct(t_list **stack_a, t_list **stack_b, int *n);
char	*get_next_line(int fd);

// a suppr :
void	lstprint(t_list *lst);

#endif
