/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:43:57 by chrstein          #+#    #+#             */
/*   Updated: 2024/01/17 16:46:02 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_elem(t_list **lst)
{
	int		i;
	long	max;
	t_list	*ptr;
	t_list	*ptr_max;

	ptr_max = NULL;
	i = ft_lstsize(*lst) + 1;
	while (--i)
	{
		ptr = *lst;
		max = -2147483649;
		while (ptr)
		{
			if (!ptr->index && *((long *)ptr->content) > max)
			{
				max = *((long *)ptr->content);
				ptr_max = ptr;
			}
			ptr = ptr->next;
		}
		ptr_max->index = i;
	}
	return (1);
}

int	check_double(t_list **lst)
{
	t_list	*ptr1;
	t_list	*ptr;

	ptr1 = *lst;
	while (ptr1->next)
	{
		ptr = ptr1->next;
		while (ptr)
		{
			if (*((long *)ptr->content) == *((long *)ptr1->content))
				return (0);
			ptr = ptr->next;
		}
		ptr1 = ptr1->next;
	}
	return (1);
}

int	check_overflow(t_list *new, char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (*((long *)new->content) > INT_MAX || *((long *)new->content) < INT_MIN)
		return (0);
	if (*((long *)new->content) == 0)
		while (--len)
			if (!(arg[len] == '0' || arg[len] == '-'))
				return (0);
	if (*((long *)new->content) == -1)
		if (*arg != '-' || arg[len - 1] != '1')
			return (0);
	return (1);
}

int	parse(t_list **stack_a, char **args)
{
	int		i;
	long	*value;
	t_list	*new;

	i = -1;
	while (args[++i])
	{
		value = malloc(sizeof(long *));
		new = ft_lstnew(value);
		if (!new || !value)
			return (free(value), 0);
		*value = ft_atol(args[i]);
		if (!check_overflow(new, args[i]))
		{
			free(value);
			free(new);
			return (0);
		}
		new->index = 0;
		new->index_base = NULL;
		ft_lstadd_back(stack_a, new);
	}
	if (!check_double(stack_a))
		return (0);
	return (index_elem(stack_a));
}
