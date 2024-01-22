/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorte_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:52:23 by chrstein          #+#    #+#             */
/*   Updated: 2024/01/17 16:53:06 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorte_3(t_list **stack_a)
{
	t_list	*ptr;

	ptr = *stack_a;
	if (ptr->index > ptr->next->index)
	{
		if (ptr->index < ptr->next->next->index)
			return (ft_putstr_fd("sa\n", 1), swap(stack_a));
		if (ptr->next->index < ptr->next->next->index)
			return (ft_putstr_fd("ra\n", 1), rotate(stack_a));
		return (ft_putstr_fd("sa\nrra\n", 1), swap(stack_a), r_rotate(stack_a));
	}
	if (ptr->index > ptr->next->next->index)
		return (ft_putstr_fd("rra\n", 1), r_rotate(stack_a));
	if (ptr->next->index > ptr->next->next->index)
		return (ft_putstr_fd("sa\nra\n", 1), swap(stack_a), rotate(stack_a));
}

int	find_min_place(t_list *stack)
{
	int		min;
	int		place;
	t_list	*begin;

	min = INT_MAX;
	begin = stack;
	while (begin)
	{
		if (min > begin->index)
			min = begin->index;
		begin = begin->next;
	}
	place = 0;
	while (stack && stack->index != min)
	{
		place++;
		stack = stack->next;
	}
	return (place);
}

void	put_min_on_top(t_list **stack_a, int size_a)
{
	t_list	*a;
	int		min_place;

	a = *stack_a;
	min_place = find_min_place(a);
	dprintf(2, "%d min place %d\n", min_place, a->index);
	if (min_place <= size_a / 2)
	{
		dprintf(2, "size_a / 2 = %d  min place %d\n", size_a / 2, min_place);
		while (min_place--)
		{
			dprintf(2, "RA ICI\n");
			ra(stack_a);
		}
	}
	else
	{
		dprintf(2, "RRA ICI\n");
		dprintf(2, "size %d min %d\n", size_a, min_place);
		while (size_a >= min_place++)
		{
			rra(stack_a);
		}
	}
}

void	selec_sorte(t_list **stack_a, t_list **stack_b, int size_a)
{
	while (size_a > 3)
	{
		put_min_on_top(stack_a, size_a);
		pb(stack_a, stack_b);
		size_a--;
	}
	sorte_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sorte_stack(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		return (ft_putstr_fd("sa\n", 1), swap(stack_a));
	if (size < 6)
		return (selec_sorte(stack_a, stack_b, size));
	if (size < 600)
		return (special_sorte(stack_a, stack_b, size));
	else
		return (radix(stack_a, stack_b, "01"));
}
