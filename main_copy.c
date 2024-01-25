/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:35:02 by chrstein          #+#    #+#             */
/*   Updated: 2024/01/17 16:37:39 by chrstein         ###   ########.fr       */
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

void	lstprint(t_list *lst)
{
	while (lst)
	{
		// if (lst->price == -1)
		// 	printf("%ld, index = %d\n", *((long *)lst->content), lst->index);
		// else
		//	printf("%ld, index = %d, price = %d, n_i_p = %d\n", *((long *)lst->content), lst->index, lst->price, lst->nearest_index_place);
		printf("%ld, index = %d, price = %d, n_i_p = %d\n", *((long *)lst->content), lst->index, lst->price, lst->nearest_index_place);
		// printf("%ld, index = %d, base = \"%s\" = %d\n", *((long *)lst->content), lst->index, lst->index_base, lst->len_index_base);
		lst = lst->next;
	}
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
		args = ft_split(argv[1], ' ');
	else
		args = strsdup(argv);
	if (!args || !*args)
		return (ft_free_strings(args), error(&stack_a), -1);
	if (!check_args(args) || !parse(&stack_a, args))
		return (ft_free_strings(args), error(&stack_a), -1);
	ft_free_strings(args);
	size = ft_lstsize(stack_a);
	if (!is_sorte(stack_a))
		sorte_stack(&stack_a, &stack_b, size);
	// printf("\n fin = \n");
	// lstprint(stack_a);
	// printf("\n");
	// lstprint(stack_b);
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
	return (0);
}
