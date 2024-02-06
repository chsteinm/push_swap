/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sorte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:41:12 by chrstein          #+#    #+#             */
/*   Updated: 2024/02/06 16:41:15 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_nb_bigger(int index, t_list **stack_a)
{
	t_list	*a;
	int		nb_bigger;

	a = *stack_a;
	nb_bigger = 0;
	while (a)
	{
		if (index < a->index)
			nb_bigger++;
		a = a->next;
	}
	return (nb_bigger);
}

void	fill_nb_bigger(t_list **stack_a)
{
	t_list	*a;

	a = *stack_a;
	while (a)
	{
		a->nb_bigger = find_nb_bigger(a->index, stack_a);
		a = a->next;
	}
}

void	pb_good_way(t_list **stack_a, t_list **stack_b, int *size_a, int cpy)
{
	t_list	*a;

	a = *stack_a;
	if (a->nb_bigger >= *size_a * 2 / 3)
	{
		pb(stack_a, stack_b);
		*size_a -= 1;
		if (a->nb_bigger > *size_a * 2 / 3 + *size_a / 3 / 2)
		{
			a = *stack_a;
			if (a->nb_bigger >= cpy / 3)
				rb(stack_b);
			else
				rr(stack_a, stack_b);
		}
	}
	else
		ra(stack_a);
}

void	push_b_until_3_in_a(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	size;
	int	size_cpy;

	while (size_a > 10)
	{
		size = size_a;
		size_cpy = size_a;
		fill_nb_bigger(stack_a);
		while (size-- > 4)
		{
			pb_good_way(stack_a, stack_b, &size_a, size_cpy);
		}
	}
	while (size_a > 3)
	{
		put_min_on_top(stack_a, size_a);
		pb(stack_a, stack_b);
		size_a--;
	}
}

void	special_sorte(t_list **stack_a, t_list **stack_b, int size)
{
	t_strct	sizes;

	push_b_until_3_in_a(stack_a, stack_b, size);
	sorte_3(stack_a);
	sizes.size_a = 3;
	sizes.size_b = size - 3;
	while (*stack_b)
	{
		fill_price(stack_a, stack_b, sizes);
		r_and_p(stack_a, stack_b, sizes);
		sizes.size_a++;
		sizes.size_b--;
	}
	put_min_on_top(stack_a, size);
}
