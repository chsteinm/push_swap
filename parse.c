#include "push_swap.h"

int index_elem(t_list **lst)
{
    int     i;
    long    max;
    t_list  *ptr;
    t_list  *ptr_max;

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

void check_double(t_list **lst)
{
    t_list  *ptr1;
    t_list  *ptr;

    ptr1 = *lst;
    while (ptr1->next)
    {
        ptr = ptr1->next;
        while (ptr)
        {
            if (*((long *)ptr->content) == *((long *)ptr1->content))
                return (ft_lstclear(lst, &free), error());
            ptr = ptr->next;
        }
        ptr1 = ptr1->next;
    }
}

int parse(t_list **stack_a, char **args)
{
    int     i;
    long    *value;
    t_list  *new;

    i = -1;
    while (args[++i])
    {
        value = malloc(sizeof(long *));
        new = ft_lstnew(value);
        if (!new || !value)
            return (free(value), ft_lstclear(stack_a, &free), 0);
        *value = ft_atol(args[i]);
        if (*((long *)value) > 2147483647 || *((long *)value) < -2147483648)
            return (ft_lstclear(stack_a, &free), 0);
        new->index = 0;
        ft_lstadd_back(stack_a, new);
    }
    check_double(stack_a);
    return (index_elem(stack_a));
}
