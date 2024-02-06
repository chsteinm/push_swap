/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_and_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:03:55 by chrstein          #+#    #+#             */
/*   Updated: 2024/02/06 17:03:56 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_up(t_list **s_a, t_list **s_b, t_list *to_push)
{
	if (to_push->nearest_index_place <= to_push->place)
	{
		while (to_push->nearest_index_place)
		{
			to_push->nearest_index_place--;
			rr(s_a, s_b);
		}
		while (*s_b != to_push)
			rb(s_b);
	}
	else
	{
		while (*s_b != to_push && to_push->nearest_index_place--)
			rr(s_a, s_b);
		while (to_push->nearest_index_place)
		{
			to_push->nearest_index_place--;
			ra(s_a);
		}
	}
}

void	r_down(t_list **s_a, t_list **s_b, t_list *to_push, t_strct sizes)
{
	if (sizes.size_a - to_push->nearest_index_place < \
	sizes.size_b - to_push->place)
	{
		while (++to_push->nearest_index_place != sizes.size_a + 1)
			rrr(s_a, s_b);
		while (*s_b != to_push)
			rrb(s_b);
	}
	else
	{
		while (*s_b != to_push && to_push->nearest_index_place++)
			rrr(s_a, s_b);
		while (++to_push->nearest_index_place != sizes.size_a + 1)
			rra(s_a);
	}
}

void	r_up_down(t_list **s_a, t_list **s_b, t_list *to_push, t_strct sizes)
{
	if (to_push->place + 1 <= sizes.size_b / 2)
		while (*s_b != to_push)
			rb(s_b);
	else
		while (*s_b != to_push)
			rrb(s_b);
	if (to_push->nearest_index_place + 1 <= sizes.size_a / 2)
		while (to_push->nearest_index_place--)
			ra(s_a);
	else
		while (++to_push->nearest_index_place != sizes.size_a + 1)
			rra(s_a);
}

t_list	*find_to_push(t_list *b)
{
	int		min_price;
	t_list	*to_push;
	int		place;

	min_price = INT_MAX;
	place = 0;
	while (b)
	{
		if (min_price > b->price)
		{
			min_price = b->price;
			to_push = b;
		}
		b->place = place;
		place++;
		b = b->next;
	}
	return (to_push);
}

void	r_and_p(t_list **s_a, t_list **s_b, t_strct sizes)
{
	t_list	*to_push;
	t_list	*a;
	t_list	*b;

	to_push = find_to_push(*s_b);
	if (to_push->place + 1 <= sizes.size_b / 2 && \
	to_push->nearest_index_place + 1 <= sizes.size_a / 2)
		r_up(s_a, s_b, to_push);
	else if (to_push->place + 1 > sizes.size_b / 2 && \
	to_push->nearest_index_place + 1 > sizes.size_a / 2)
		r_down(s_a, s_b, to_push, sizes);
	else
		r_up_down(s_a, s_b, to_push, sizes);
	a = *s_a;
	b = *s_b;
	if (a->index < b->index)
		ra(s_a);
	pa(s_a, s_b);
}
