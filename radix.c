#include "push_swap.h"

int	fill_base_and_ret_maxlen(t_list **stack, char *base)
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

void	ra_or_pb(t_list **stack_a, t_list **stack_b, int it)
{
	t_list	*a;

	a = *stack_a;
	//printf("%ld, index = %d, base = \"%s\" = %d, it = %d\n", *((long *)a->content), a->index, a->index_base, a->len_index_base, it);
	if (a->len_index_base - it >= 0 && a->index_base[a->len_index_base - it] == '1')
		ra(stack_a);
	else
		pb(stack_a, stack_b);
}

void	radix(t_list **stack_a, t_list **stack_b, int size)
{
	int		it;
	int		maxlen;
	int		tmp_size;

	maxlen = fill_base_and_ret_maxlen(stack_a, "01");
	it = 0;
	while (++it <= maxlen)
	{
		tmp_size = size;
		while (tmp_size--)
			ra_or_pb(stack_a, stack_b, it);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}
