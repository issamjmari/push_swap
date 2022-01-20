#include "push_swap.h"

int		is_int (char *str)
{
	int	i;
	int negative;

	i = 0;
	negative = 0;
	if (str[i] == '-')
		i++;
	if (ft_atoi(str) > 2147483647
	|| ft_atoi(str) < -2147483648)
		return 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	check (char **av)
{
	int	i;
	int j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (j != i)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				write (2, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		if (!is_int(av[i]))
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

void	handle_3 (t_list *a)
{
	if (a->content < a->next->content
	&& a->next->content < a->next->next->content)
		return ;
	if (a->content < a->next->content
	&& a->content < a->next->next->content)
	{
		swapa (&a);
		rotatea (&a);
	}
	else if (a->content > a->next->content
	&& a->content < a->next->next->content)
		swapa (&a);
	else if (a->content < a->next->content
	&& a->content > a->next->next->content)
		rrotatea (&a);
	else if (a->content > a->next->content
	&& a->next->content < a->next->next->content)
		rotatea (&a);
	else if (a->content > a->next->content
	&& a->next->content > a->next->next->content)
	{
		swapa (&a);
		rrotatea (&a);
	}
}
void	bring_front_or_back (t_list **stack, int wanted, int size, int med)
{
	if (wanted <= med)
	{
		while (wanted)
		{
			rotatea(stack);
			wanted--;
		}
	}
	else
	{
		while (wanted != size)
		{
			rrotatea(stack);
			wanted++;
		}
	}
}

int	smallest_pos(t_list *stack)
{
	int	position;
	int	smallest;
	int ret;

	position = 0;
	ret = 0;
	smallest = stack->content;
	while (stack)
	{
		if (stack->content < smallest) 
		{
			smallest = stack->content;
			ret = position;
		}
		position++;
		stack = stack->next;
	}
	return (ret);
}
int	smallest(t_list *stack)
{
	int	smallest;

	smallest = stack->content;
	while (stack)
	{
		if (stack->content < smallest) 
			smallest = stack->content;
		stack = stack->next;
	}
	return (smallest);
}
void	handle_5n4 (t_list **a, t_list **b, int size)
{
	int smallest;

	smallest = smallest_pos (*a);
	bring_front_or_back (a, smallest, size, size / 2);
	pushb (b, a);
	if (size == 5)
	{
		smallest = smallest_pos (*a);
		bring_front_or_back (a, smallest, size, size / 2);
		pushb (b, a);
	}
	handle_3 (*a);
	pusha(a, b);
	if (size == 5)
	{
		pusha(a, b);
		if ((*a)->content > (*a)->next->content)
			swapa (a);
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
			swapa (&a);
	if (size == 3)
		handle_3(a);
	if (size == 5 || size == 4)
		handle_5n4(&a, &b, size);
	else if (size > 5)
		sort1 (a, b);
	// print_stack (a);
}
