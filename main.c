#include "push_swap.h"

void    error()
{
    ft_putstr_fd("Error\n", 2);
    exit(1);
}

int check_args(char **args)
{
    int i;
    char    *ptr;

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

int is_sorte(t_list *stack_a)
{
    int i;

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

void    lstprint(t_list *lst)
{
    while (lst)
    {
        printf("%ld, index = %d\n", *((long *)lst->content), lst->index);
        lst = lst->next;
    }
}

int main(int argc, char **argv)
{
    char **args;
    t_list *stack_a;

    if (argc == 1)
        return (1);
    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        if (!args)
            error();
    }
    else
        args = argv + 1;
    stack_a = NULL;
    if (!check_args(args) || !parse(&stack_a, args))
        error();
    sorte_stack(&stack_a);
    lstprint(stack_a);
    ft_lstclear(&stack_a, &free);
    return (0);
}
