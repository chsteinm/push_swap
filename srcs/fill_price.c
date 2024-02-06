/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:48:17 by chrstein          #+#    #+#             */
/*   Updated: 2024/02/06 16:48:18 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_the_nearest_index(t_list *a, t_list *b)
{
	int		near;
	int		i;
	t_list	*cpy;

	cpy = a;
	near = INT_MAX;
	i = 0;
	b->nearest_index_place = 0;
	while (a)
	{
		if (b->index < a->index && near > a->index - b->index)
		{
			b->nearest_index_place = i;
			near = a->index - b->index;
			b->near_diff = near;
		}
		a = a->next;
		i++;
	}
}

int	count_moves_2(t_list *b, int place_b, t_strct sizes)
{
	int	count;

	count = 0;
	if (place_b + 1 <= sizes.size_b / 2)
		count += place_b;
	else
		count += sizes.size_b - place_b;
	if (b->nearest_index_place + 1 <= sizes.size_a / 2)
		count += b->nearest_index_place;
	else
		count += sizes.size_a - b->nearest_index_place;
	return (count);
}

int	count_moves(t_list *a, t_list *b, int place_b, t_strct sizes)
{
	find_the_nearest_index(a, b);
	if (place_b + 1 <= sizes.size_b / 2 && \
	b->nearest_index_place + 1 <= sizes.size_a)
	{
		if (b->nearest_index_place <= place_b)
			return (place_b);
		return (b->nearest_index_place);
	}
	if (place_b + 1 > sizes.size_b / 2 && \
	b->nearest_index_place + 1 > sizes.size_a / 2)
	{
		if (sizes.size_a - b->nearest_index_place < sizes.size_b - place_b)
			return (sizes.size_b - place_b);
		return (sizes.size_a - b->nearest_index_place);
	}
	return (count_moves_2(b, place_b, sizes));
}

void	fill_price(t_list **stack_a, t_list **stack_b, t_strct sizes)
{
	t_list	*ptr;
	int		place;

	place = 0;
	ptr = *stack_b;
	while (ptr)
	{
		ptr->price = count_moves(*stack_a, ptr, place, sizes);
		ptr->price += ptr->near_diff + (sizes.size_b - ptr->index);
		ptr = ptr->next;
		place++;
	}
}
