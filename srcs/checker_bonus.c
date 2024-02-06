/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:11:45 by chrstein          #+#    #+#             */
/*   Updated: 2024/01/17 17:12:43 by chrstein         ###   ########.fr       */
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

void	replace_white_space(char *argv)
{
	while (*argv)
	{
		if (ft_iswhitespace(*argv))
			*argv = ' ';
		argv++;
	}
}

int	main(int argc, char **argv)
{
	char	**args;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		replace_white_space(argv[1]);
		args = ft_split(argv[1], ' ');
	}
	else
		args = strsdup(argv + 1, argc - 1);
	if (!args || !*args)
		return (ft_free_strings(args), error(&stack_a), -1);
	if (!check_args(args) || !parse(&stack_a, args))
		return (ft_free_strings(args), error(&stack_a), -1);
	ft_free_strings(args);
	while (1)
		instruct(&stack_a, &stack_b);
	return (0);
}
