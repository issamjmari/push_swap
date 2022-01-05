#include "push_swap.h"


void	check (char **av)
{
	int	i;
	int j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (ft_strncmp("-10", av[i], 3) != 0 && ft_atoi(av[i]) == -10)
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		while (j != i)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				write (2, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	handle_3 (t_list *a)
{
	if (a->content < a->next->content
	&& a->content < a->next->next->content)
	{
		swaplst (&a);
		rotate (&a);
	}
	else if (a->content > a->next->content
	&& a->content < a->next->next->content)
		swaplst (&a);
	else if (a->content < a->next->content
	&& a->content > a->next->next->content)
		rrotate (&a);
	else if (a->content > a->next->content
	&& a->next->content < a->next->next->content)
		rotate (&a);
	else if (a->content > a->next->content
	&& a->next->content > a->next->next->content)
	{
		swaplst (&a);
		rrotate (&a);
	}
}
void	handle_4 (t_list *a, t_list *b)
{
	push (&b, &a);
	handle_3 (a);
	push (&a, &b);
	if (a->content > a->next->content
	&& a->content > a->next->next->content
	&& a->content > a->next->next->next->content)
		rotate (&a);
	else if (a->content > a->next->content
	&& a->content < a->next->next->content
	&& a->content < a->next->next->next->content)
		swaplst (&a);
	else if (a->content > a->next->content
	&& a->content > a->next->next->content
	&& a->content < a->next->next->next->content)
	{
		rrotate (&a);
		swaplst (&a);
		rotate (&a);
		rotate (&a);
	}
}
void handle_5 (t_list *a, t_list *b)
{
	push(&b, &a);
	handle_4 (a, b);
	push(&a, &b);
	if (a->content > a->next->content
	&& a->content > a->next->next->content
	&& a->content > a->next->next->next->content
	&& a->content > a->next->next->next->next->content)
		rotate (&a);
	if (a->content > a->next->content
	&& a->content > a->next->next->content
	&& a->content > a->next->next->next->content
	&& a->content < a->next->next->next->next->content)
	{
		rrotate (&a);
		swaplst (&a);
		rotate (&a);
		rotate (&a);
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
	check (&av[1]);
	a = ft_lstnew (ft_atoi(av[1]));
	while (av[i])
	{
		ft_lstadd_back (&a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	size = ft_lstsize (a);
	if (size == 2)
		if (a->content > a->next->content)
			swaplst (&a);
	if (size == 3)
	{
		if (a->content < a->next->content
		&& a->next->content < a->next->next->content)
			return 0;
		handle_3(a);
	}
	if (size == 4)
		handle_4 (a, b);
	if (size == 5)
		handle_5(a, b);
}