/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:41:37 by chrstein          #+#    #+#             */
/*   Updated: 2024/01/17 16:41:55 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **b)
{
	ft_putstr_fd("sb\n", 1);
	swap(b);
}

void	ss(t_list **a, t_list **b)
{
	ft_putstr_fd("ss\n", 1);
	swap(b);
	swap(a);
}

void	pa(t_list **a, t_list **b)
{
	ft_putstr_fd("pa\n", 1);
	push(a, b);
}

void	pb(t_list **a, t_list **b)
{
	ft_putstr_fd("pb\n", 1);
	push(b, a);
}

void	ra(t_list **a)
{
	ft_putstr_fd("ra\n", 1);
	rotate(a);
}
