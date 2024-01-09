#include "push_swap.h"

void	instruct(t_list **stack_a, t_list **stack_b)
{
	char	ins[4];

	printf("enter instruction :\n");
	scanf("%s", ins);
	if (ins[0] == 's')
	{
		if (ins[1] == 'a')
			swap(stack_a);
		else if (ins[1] == 'b')
			swap(stack_b);
		else if (ins[1] == 's')
		{
			swap(stack_a);
			swap(stack_b);
		}
		else
			return (ft_lstclear(stack_a, &free), ft_lstclear(stack_b, &free), error());
	}
	else if (ins[0] == 'p')
	{
		if (ins[1] == 'a')
			push(stack_a, stack_b);
		else if (ins[1] == 'b')
			push(stack_b, stack_a);
		else
			return (ft_lstclear(stack_a, &free), ft_lstclear(stack_b, &free), error());
	}
	else if (ins[0] == 'r')
	{
		if (ins[1] == 'a')
			rotate(stack_a);
		else if (ins[1] == 'b')
			rotate(stack_b);
		else if (ins[1] == 'r')
		{
			if (ins[2] == '\0')
			{
				rotate(stack_a);
				rotate(stack_b);
			}
			else if (ins[2] == 'a')
				r_rotate(stack_a);
			else if (ins[2] == 'b')
				r_rotate(stack_b);
			else if (ins[2] == 'r')
			{
				r_rotate(stack_a);
				r_rotate(stack_b);
			}
			else
				return (ft_lstclear(stack_a, &free), ft_lstclear(stack_b, &free), error());
		}
	}
	else
		return (ft_lstclear(stack_a, &free), ft_lstclear(stack_b, &free), error());
}
