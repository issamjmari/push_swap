#include "push_swap.h"
#include "get_next_line/get_next_line.h"

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

void	check_if_sorted (t_list *a, t_list *b)
{
	int pos;

	pos = 0;
	// print_stack(a);
	while (a)
	{
		if (a->next && a->content > a->next->content)
		{
			write (1, "KO\n", 3);
			exit (1);
		}
		pos++;
		a = a->next;
	}
	write (1, "OK\n", 3);
}
// void    print_stack(t_list *stack)
// {
// 	while (stack)
// 	{
// 		printf ("%d\n", stack->content);
// 		stack = stack->next;
// 	}
// }
void    rx_instructions (t_list *a, t_list *b)
{
    char    *inst;

	int fd = open ("ch.txt", O_RDWR);
    inst = get_next_line (0);
    while (inst)
    {
        if (!strncmp(inst, "ra\n", 2))
            rotatea (&a);
        else if (!strncmp(inst, "rra\n", 3))
            rrotatea (&a);
        else if (!strncmp(inst, "rb\n", 2))
            rotateb (&b);
        else if (!strncmp(inst, "rrb\n", 3))
            rrotateb (&b);
        else if (!strncmp(inst, "sa\n", 2))
            swapa (&a);
        else if (!strncmp(inst, "sb\n", 2))
            swapb (&b);
        else if (!strncmp(inst, "pa\n", 2))
            pusha (&a, &b);
        else if (!strncmp(inst, "pb\n", 2))
            pushb (&b, &a);
        else if (!strncmp(inst, "ss\n", 2))
            swapboth (&b, &a);
		free (inst);
        inst = get_next_line (0);
    }
}
// void    print_stack(t_list *stack)
// {
// 	while (stack)
// 	{
// 		printf ("%d\n", stack->content);
// 		stack = stack->next;
// 	}
// }
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
    rx_instructions(a, b);
	check_if_sorted(a, b);
}