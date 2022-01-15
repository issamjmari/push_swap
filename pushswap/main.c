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
void	bringfront (t_list **stack, int smallest)
{
	while (smallest)
	{
		rotatea(stack);
		smallest--;
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
void	handle_5n4 (t_list *a, t_list *b, int size)
{
	int smallest;

	smallest = smallest_pos (a);
	bringfront (&a, smallest);
	pushb (&b, &a);
	if (size == 5)
	{
		smallest = smallest_pos (a);
		bringfront (&a, smallest);
		pushb (&b, &a);
	}
	handle_3 (a);
	pusha(&a, &b);
	if (size == 5)
	{
		pusha(&a, &b);
		if (a->content > a->next->content)
			swapa (&a);
	}
}
void    print_stack(t_list *stack)
{
	while (stack)
	{
		printf ("%d\n", stack->content);
		stack = stack->next;
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
	// if (size == 2)
	// 	if (a->content > a->next->content)
	// 		swapa (&a);
	// if (size == 3)
	// {
	// 	handle_3(a);
	// }
	if (size == 5 || size == 4)
		handle_5n4(a, b, size);
	if (size > 5)
		sort1 (a, b);
}