/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:02 by chrstein          #+#    #+#             */
/*   Updated: 2024/01/17 16:39:32 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_list **lst)
{
	ft_lstclear(lst, &free);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check_args(char **args)
{
	int		i;
	char	*ptr;

	i = -1;
	while (args[++i])
	{
		ptr = args[i];
		if (*ptr == '-' || *ptr == '+')
			ptr++;
		if (!*ptr)
			return (0);
		while (*ptr)
		{
			if (*ptr < '0' || *ptr > '9')
				return (0);
			ptr++;
		}
	}
	return (1);
}

int	is_sorte(t_list *stack_a)
{
	int	i;

	i = 1;
	while (stack_a)
	{
		if (stack_a->index != i)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**args;
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			error(&stack_a);
	}
	else
		args = argv + 1;
	if (!check_args(args) || !parse(&stack_a, args))
		error(&stack_a);
	size = ft_lstsize(stack_a);
	if (!is_sorte(stack_a))
		sorte_stack(&stack_a, &stack_b, size);
	ft_lstclear(&stack_a, &free);
	return (0);
}
