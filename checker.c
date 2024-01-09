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

void	lstsprint(t_list *a, t_list *b, int n)
{
	printf("%dth move :\n\n", n);
	while (a || b)
	{
		if (a && b)
		{
			printf("%d   |   %d\n", a->index, b->index);
			a = a->next;
			b = b->next;
		}
		else if (a)
		{
			printf("%d   |\n", a->index);
			a = a->next;
		}
		else if (b)
		{
			printf("    |   %d\n", b->index);
			b = b->next;
		}
	}
	printf("\n\n");
}

int	main(int argc, char **argv)
{
	char **args;
    t_list *stack_a;
    t_list *stack_b;
	int		size;

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
    stack_b = NULL;
    if (!check_args(args) || !parse(&stack_a, args))
        error();
	size = ft_lstsize(stack_a);
	int n = 0;
    while (stack_b || !is_sorte(stack_a))
	{
		lstsprint(stack_a, stack_b, n);
		instruct(&stack_a, &stack_b);
		n++;
	}
	printf("Congrate! Win with %d moves!\n", n);
    ft_lstclear(&stack_a, &free);
    return (0);
}
