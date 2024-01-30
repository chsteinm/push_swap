#include "push_swap.h"

int		find_nb_bigger(t_list **stack_a)
{
	t_list	*a;
	int		index;
	int		nb_bigger;

	a = *stack_a;
	index = a->index;
	nb_bigger = 0;
	while (a)
	{
		if (index < a->index)
			nb_bigger++;
		a = a->next;
	}
	return (nb_bigger);
}

void	push_b_until_3_in_a(t_list **stack_a, t_list **stack_b, int size_a)
{
	int		nb_bigger;
	int		size;

	while (size_a > 10)
	{
		size = size_a;
		while (size-- > size_a / 4 + 3)
		{
			nb_bigger = find_nb_bigger(stack_a);
			if (nb_bigger >= size_a * 2 / 3 && size_a > 15)
			{
				pb(stack_a, stack_b);
				size_a--;
				nb_bigger = find_nb_bigger(stack_a);
				//dprintf(1, "nb_b = %d --\n", nb_bigger);
				if (nb_bigger >= size_a / 3)
					rb(stack_b);
				else
					rr(stack_a, stack_b);
			}
			else if (nb_bigger >= size_a / 3)
			{
				pb(stack_a, stack_b);
				size_a--;
			}
			else
				ra(stack_a);
		}
	}
	while (size_a > 3)
	{
		put_min_on_top(stack_a, size_a);
		pb(stack_a, stack_b);
		size_a--;
	}
}

// void	push_b_until_3_in_a(t_list **stack_a, t_list **stack_b, int size_a)
// {
// 	t_list	*a;
// 	int		size;
// 	int		o_size;

// 	o_size = size_a;
// 	a = *stack_a;
// 	size = size_a;
// 	while (size_a > 3)
// 	{
// 		// dprintf(2, "index a = %d tier = %d\n", a->index, size * 2 / 3);
// 		if (a->index > size * 2 / 3 || a->index == o_size)
// 			ra(stack_a);
// 		else
// 		{
// 			pb(stack_a, stack_b);
// 			size_a--;
// 			size++;
// 		}
// 		a = *stack_a;
// 	}
// }

void	special_sorte(t_list **stack_a, t_list **stack_b, int size)
{
	int	size_a;
	int	size_b;

	push_b_until_3_in_a(stack_a, stack_b, size);
	sorte_3(stack_a);
	size_a = 3;
	size_b = size - 3;
	while (*stack_b)
	{
		fill_price(stack_a, stack_b, size_b);
		// printf("\n a =\n");
		// lstprint(*stack_a);
		// printf("\n b =\n");
		// lstprint(*stack_b);
		r_and_p(stack_a, stack_b, size_a, size_b);
		size_a++;
		size_b--;
	}
	put_min_on_top(stack_a, size);
}
