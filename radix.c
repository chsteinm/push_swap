#include "push_swap.h"

int	fill_base_and_ret_maxlen(t_list **stack, const char *base)
{
	t_list	*ptr;
	int		maxlen;

	maxlen = 0;
	ptr = *stack;
	while (ptr)
	{
		ptr->index_base = ft_itoa_base(ptr->index, base);
		if (!ptr->index_base)
			error(stack);
		ptr->len_index_base = ft_strlen(ptr->index_base);
		if (maxlen < ptr->len_index_base)
			maxlen = ptr->len_index_base;
		ptr = ptr->next;
	}
	return (maxlen);
}

void	ra_or_pb(t_list **stack_a, t_list **stack_b, int it, char min_digit)
{
	t_list	*a;
	int		size_a;

	size_a = ft_lstsize(*stack_a);
	while (size_a--)
	{
		a = *stack_a;
		//printf("%ld, index = %d, base = \"%s\" = %d, it = %d\n", *((long *)a->content), a->index, a->index_base, a->len_index_base, it);
		if (a->len_index_base - it >= 0 && a->index_base[a->len_index_base - it] != min_digit)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
}

void	radix(t_list **stack_a, t_list **stack_b, const char *base)
{
	int		it;
	int		maxlen;
	int		len_base;
	int		i_want_a_for_loop;

	maxlen = fill_base_and_ret_maxlen(stack_a, base);
	len_base = ft_strlen(base);
	it = 0;
	while (++it <= maxlen)
	{
		i_want_a_for_loop = -1;
		while (++i_want_a_for_loop < len_base - 1)
		{
			ra_or_pb(stack_a, stack_b, it, base[i_want_a_for_loop]);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}
