#include "push_swap.h"

void	handle_3 (t_list *a)
{
	if (a->content > a->next->content
	&& a->content > a->next->next->content)
	{
		rrotate (&a);
		swaplst (a->next);
	}
	else if (a->content == a->next->content
	&& a->content > a->next->next->content)
		rrotate (&a);
	else if (a->content == a->next->next->content
	&& a->content > a->next->content)
		swaplst (a);
	else if (a->content < a->next->content
	&& a->content > a->next->next->content)
		rrotate (&a);
	while (a)
	{
		printf ("%d\n", a->content);
		a = a->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		size;

	i = 2;
	b = NULL;
	a = ft_lstnew (ft_atoi(av[1]));
	while (av[i])
	{
		ft_lstadd_back (&a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	size = ft_lstsize (a);
	if (size <= 3)
		handle_3(a);
}