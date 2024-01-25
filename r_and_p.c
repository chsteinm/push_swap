#include "push_swap.h"

void	r_up(t_list **stack_a, t_list **stack_b, t_list *to_push)
{
	if (to_push->nearest_index_place <= to_push->place)
	{
		while (to_push->nearest_index_place)
		{
			to_push->nearest_index_place--;
			rr(stack_a, stack_b);
		}
		while (*stack_b != to_push)
			rb(stack_b);
	}
	else
	{
		while (*stack_b != to_push && to_push->nearest_index_place--)
			rr(stack_a, stack_b);
		while (to_push->nearest_index_place)
		{
			to_push->nearest_index_place--;
			ra(stack_a);
		}
	}
}

void	r_down(t_list **stack_a, t_list **stack_b, t_list *to_push, t_strct sizes)
{
	if (sizes.size_a - to_push->nearest_index_place < sizes.size_b - to_push->place)
	{
		while (++to_push->nearest_index_place != sizes.size_a + 1)
			rrr(stack_a, stack_b);
		while (*stack_b != to_push)
			rrb(stack_b);
	}
	else
	{
		while (*stack_b != to_push && to_push->nearest_index_place++)
			rrr(stack_a, stack_b);
		while (++to_push->nearest_index_place != sizes.size_a + 1)
			rra(stack_a);
	}
}

void	r_up_down(t_list **stack_a, t_list **stack_b, t_list *to_push, t_strct sizes)
{
	if (to_push->place <= sizes.size_b / 2)
		while (*stack_b != to_push)
			rb(stack_b);
	else
		while (*stack_b != to_push)
			rrb(stack_b);
	if (to_push->nearest_index_place + 1 <= sizes.size_a / 2)
		while (to_push->nearest_index_place--)
			ra(stack_a);
	else
		while (++to_push->nearest_index_place != sizes.size_a + 1)
			rra(stack_a);

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

void	r_and_p(t_list **stack_a, t_list **stack_b, int size_a, int size_b)
{
	t_list	*to_push;
	t_list	*a;
	t_list	*b;
	t_strct	sizes;

	sizes.size_a = size_a;
	sizes.size_b = size_b;
	to_push = find_to_push(*stack_b);
	if (to_push->place + 1 <= size_b / 2 && to_push->nearest_index_place + 1 <= size_a / 2)
		r_up(stack_a, stack_b, to_push);
	else if (to_push->place > size_b / 2 && to_push->nearest_index_place > size_a / 2)
		r_down(stack_a, stack_b, to_push, sizes);
	else
		r_up_down(stack_a, stack_b, to_push, sizes);
	a = *stack_a;
	b = *stack_b;
	if (a->index < b->index)
		ra(stack_a);
	pa(stack_a, stack_b);
}
