#include "push_swap.h"

int		find_the_nearest_index(t_list *a, int index_b)
{
	int		place_a;
	int		near;
	int		i;
	
	near = INT_MAX;
	i = 0;
	place_a = 0;
	while (a)
	{
		if (index_b > a->index && near > index_b - a->index)
		{
			place_a = i;
			near = index_b - a->index;
		}
		a = a->next;
		i++;
	}
	return (place_a);
}

int		a_sup_b(int place_a, int size_a, int place_b, int size_b)
{
	if (place_a <= size_a / 2 && place_b <= size_b / 2)
		return (place_a);
	if (place_a > size_a / 2 && place_b <= size_b / 2)
		return (size_a - place_a + 1 + place_b);
	if (place_a > size_a / 2 && place_b > size_b / 2)
		return (size_b - place_b + 1);
	if (place_a <= size_a / 2 && place_b > size_b / 2)
		return (place_a + size_b - place_b + 1);
	return (-3);
}

int		a_inf_b(int place_a, int size_a, int place_b, int size_b)
{
	if (place_a <= size_a / 2 && place_b <= size_b / 2)
		return (place_b);
	if (place_a > size_a / 2 && place_b <= size_b / 2)
		return (size_a - place_a + 1 + place_b);
	if (place_a > size_a / 2 && place_b > size_b / 2)
		return (size_a - place_a + 1);
	if (place_a <= size_a / 2 && place_b > size_b / 2)
		return (place_a + size_b - place_b + 1);
	return (-11);
}
//mettre un else a la place du dernier if (au 2 autres fonctions aussi)
int		count_moves(t_list *a, t_list *b, int place_b, int size_b)
{
	int		size_a;

	size_a = ft_lstsize(a);
	b->nearest_index_place = find_the_nearest_index(a, b->index);
	if (b->nearest_index_place >= place_b)
		return (a_sup_b(b->nearest_index_place, size_a, place_b, size_b));
	if (b->nearest_index_place < place_b)
		return (a_inf_b(b->nearest_index_place, size_a, place_b, size_b));
	return (-2);
}

void	fill_price(t_list **stack_a, t_list **stack_b, int size_b)
{
	t_list	*ptr;
	int		place;

	place = 0;
	ptr = *stack_b;
	while (ptr)
	{
		ptr->price = count_moves(*stack_a, ptr, place, size_b);
		ptr = ptr->next;
		place++;
	}
}