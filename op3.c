#include "push_swap.h"

void	rb(t_list **b)
{
	ft_putstr_fd("rb\n", 1);
	rotate(b);
}

void	rr(t_list **a, t_list **b)
{
	ft_putstr_fd("rr\n", 1);
	rotate(b);
	rotate(a);
}

void	rra(t_list **a)
{
	ft_putstr_fd("rra\n", 1);
	r_rotate(a);
}

void	rrb(t_list **b)
{
	ft_putstr_fd("rrb\n", 1);
	r_rotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	ft_putstr_fd("rrr\n", 1);
	r_rotate(b);
	r_rotate(a);
}