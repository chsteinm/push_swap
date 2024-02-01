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
	// if (place_a == 0)
	// 	return (find_min_place(cpy));
}

//mettre un else a la place du dernier if (au 2 autres fonctions aussi)
int		count_moves(t_list *a, t_list *b, int place_b, int size_b)
{
	int		size_a;
	int		count;

	size_a = ft_lstsize(a);
	find_the_nearest_index(a, b);
	if (place_b + 1 <= size_b / 2 && b->nearest_index_place + 1 <= size_a)
	{
		if (b->nearest_index_place <= place_b)
			return (place_b);
		return (b->nearest_index_place);
	}
	if (place_b + 1 > size_b / 2 && b->nearest_index_place + 1 > size_a / 2)
	{
		// dprintf(2, "s_b = %d - p_b = %d\n", size_b, place_b);
		if (size_a - b->nearest_index_place < size_b - place_b)
			return (size_b - place_b);
		return (size_a - b->nearest_index_place);
	}
	count = 0;
	if (place_b + 1 <= size_b / 2)
		count += place_b;
	else
		count += size_b - place_b;
	if (b->nearest_index_place + 1 <= size_a / 2)
		count += b->nearest_index_place;
	else
		count += size_a - b->nearest_index_place;
	return (count);
}

void	fill_price(t_list **stack_a, t_list **stack_b, int size_b)
{
	t_list	*ptr;
	int		place;

	place = 0;
	ptr = *stack_b;
	while (ptr)
	{
		// ptr->price = count_moves(*stack_a, ptr, place, size_b);
		ptr->price = count_moves(*stack_a, ptr, place, size_b) + ptr->near_diff + size_b - ptr->index;
		ptr = ptr->next;
		place++;
	}
}