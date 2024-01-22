#include "push_swap.h"

void	push_b_until_3_in_a(t_list **stack_a, t_list **stack_b, int size_a)
{
	t_list	*a;
	int		size;

	a = *stack_a;
	size = size_a;
	while (size_a > 7)
	{
		dprintf(2, "index a = %d tier = %d\n", a->index, size * 2 / 3);
		if (a->index > size * 2 / 3)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			size_a--;
			size++;
		}
		a = *stack_a;
	}
	while (size_a-- > 3)
	{
		put_min_on_top(stack_a, size_a);
		pb(stack_a, stack_b);
	}
}

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
		printf("\n a =\n");
		lstprint(*stack_a);
		printf("\n b =\n");
		lstprint(*stack_b);
		r_and_p(stack_a, stack_b, size_a, size_b);
		size_a++;
		size_b--;
	}
}
