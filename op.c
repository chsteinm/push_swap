#include "push_swap.h"

void    swap(t_list **stack)
{
    t_list  *one;
    t_list  *two;

    one = *stack;
    if (!one || !one->next)
        return ;
    two = one->next;
    one->next = two->next;
    two->next = one;
    *stack = two;
}
void	push(t_list **a, t_list **b)
{
	t_list	*first;

	first = *b;
	if (!first)
		return;
	*b = first->next;
	first->next = *a;
	*a = first;
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	if (!first)
		return ;
	last = ft_lstlast(first);
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	r_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	if (!first)
		return ;
	last = ft_lstlast(first);
	last->next = first;
	*stack = last;
	while (first->next != last)
		first = first->next;
	first->next = NULL;
}

void	sa(t_list **a)
{
	ft_putstr_fd("sa\n", 1);
	swap(a);
}