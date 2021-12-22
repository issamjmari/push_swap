#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*t;
	int		i;

	i = 2;
	a = ft_lstnew (ft_atoi(av[1]));
	while (av[i])
	{
		ft_lstadd_back (&a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	a = rotate (a);
}