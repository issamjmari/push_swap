#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;

	i = 2;
	b = NULL;
	a = ft_lstnew (1);
	a->next = ft_lstnew (2);
	// while (av[i])
	// {
	// 	ft_lstadd_back (&a, ft_lstnew(ft_atoi(av[i])));
	// 	i++;
	// }
	push (&b, a);
}