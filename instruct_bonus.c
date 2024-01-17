#include "push_swap.h"

void	instruct_r(t_list **stack_a, t_list **stack_b, char *ins)
{
	if (ins[1] == 'a' && ins[2] == '\n')
			rotate(stack_a);
		else if (ins[1] == 'b' && ins[2] == '\n')
			rotate(stack_b);
		else if (ins[1] == 'r')
		{
			if (ins[2] == '\0')
			{
				rotate(stack_a);
				rotate(stack_b);
			}
			else if (ins[2] == 'a' && ins[3] == '\n')
				r_rotate(stack_a);
			else if (ins[2] == 'b' && ins[3] == '\n')
				r_rotate(stack_b);
			else if (ins[2] == 'r' && ins[3] == '\n')
			{
				r_rotate(stack_a);
				r_rotate(stack_b);
			}
			else
				return (free(ins), ft_lstclear(stack_b, &free), error(stack_a));
		}
}

void	instruct_p(t_list **stack_a, t_list **stack_b, char *ins)
{
	if (ins[1] == 'a' && ins[2] == '\n')
			push(stack_a, stack_b);
		else if (ins[1] == 'b' && ins[2] == '\n')
			push(stack_b, stack_a);
		else
			return (free(ins), ft_lstclear(stack_b, &free), error(stack_a));
}

void	instruct_s(t_list **stack_a, t_list **stack_b, char *ins)
{
	if (ins[1] == 'a' && ins[2] == '\n')
			swap(stack_a);
		else if (ins[1] == 'b' && ins[2] == '\n')
			swap(stack_b);
		else if (ins[1] == 's' && ins[2] == '\n')
		{
			swap(stack_a);
			swap(stack_b);
		}
		else
			return (free(ins), ft_lstclear(stack_b, &free), error(stack_a));
}

void	instruct(t_list **stack_a, t_list **stack_b, char *ins)
{
	char	*ins;

	ins = get_next_line(0);
	if (!ins)
		return (ft_lstclear(stack_b, &free), error(stack_a));
	if (ins[0] == 's')
		instruct_s(stack_a, stack_b, ins);
	else if (ins[0] == 'p')
		instruct_p(stack_a, stack_b, ins);
	else if (ins[0] == 'r')
	{
		instruct_r()
	}
	else
		return (free(ins), ft_lstclear(stack_b, &free), error(stack_a));
}
