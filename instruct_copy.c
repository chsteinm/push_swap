#include "push_swap.h"

void	instruct(t_list **stack_a, t_list **stack_b, int *n)
{
	char	ins[4];

	printf("enter instruction :\n");
	scanf("%s", ins);
	printf("%s\n", ins);
	if (*ins == 'u')
	{
		*n -= 3;
		return ;
	}
	if (ins[0] == 's')
	{
		if (ins[1] == 'a' && !ins[2])
			swap(stack_a);
		else if (ins[1] == 'b' && !ins[2])
			swap(stack_b);
		else if (ins[1] == 's' && !ins[2])
		{
			swap(stack_a);
			swap(stack_b);
		}
		else
			return ;
	}
	else if (ins[0] == 'p')
	{
		if (ins[1] == 'a' && !ins[2])
			push(stack_a, stack_b);
		else if (ins[1] == 'b' && !ins[2])
			push(stack_b, stack_a);
		else
			return ;
	}
	else if (ins[0] == 'r')
	{
		if (ins[1] == 'a' && !ins[2])
			rotate(stack_a);
		else if (ins[1] == 'b' && !ins[2])
			rotate(stack_b);
		else if (ins[1] == 'r')
		{
			if (ins[2] == '\0')
			{
				rotate(stack_a);
				rotate(stack_b);
			}
			else if (ins[2] == 'a' && !ins[3])
				r_rotate(stack_a);
			else if (ins[2] == 'b' && !ins[3])
				r_rotate(stack_b);
			else if (ins[2] == 'r' && !ins[3])
			{
				r_rotate(stack_a);
				r_rotate(stack_b);
			}
			else
				return ;
		}
	}
	else
		return ;
}
