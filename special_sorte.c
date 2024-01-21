#include "push_swap.h"

void	push_b_until_3_in_a(t_list **stack_a, t_list **stack_b, int size_a)
{
	t_list	*a;

	a = *stack_a;
	while (size_a > 3)
	{
		if (a->index < size_a / 3)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			size_a--;
		}
		a = *stack_a;
		printf("%d\n", a->index);
	}
}

void	rotate_and_push_a(t_list **stack_a, t_list **stack_b)
{

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
		rotate_and_push_a(stack_a, stack_b);
		size_a++;
		size_b--;
	}
}
