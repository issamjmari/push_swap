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
void    rx_instructions (t_list *a, t_list *b)
{
    int     rd;
    char    *inst;

    rd = read(0, inst, 5);
    while (rd)
    {
        if (!strncmp(inst, "ra\n", 4))
            rotatea (&a);
        else if (!strncmp(inst, "rra\n", 4))
            rrotatea (&a);
        else if (!strncmp(inst, "rb\n", 4))
            rotateb (&a);
        else if (!strncmp(inst, "rrb\n", 4))
            rrotateb (&a);
        else if (!strncmp(inst, "sa\n", 3))
            swapa (&a);
        else if (!strncmp(inst, "sb\n", 3))
            swapb (&a);
        else if (!strncmp(inst, "pa\n", 3))
            pusha (&a, &b);
        else if (!strncmp(inst, "pb\n", 3))
            pusha (&b, &a);
        else if (!strncmp(inst, "pb\n", 3))
            pusha (&b, &a);
        else if (!strncmp(inst, "ss\n", 3))
            swapboth (&b, &a);
        rd = read(0, inst, 5);
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
    rx_instructions(a, b);
}