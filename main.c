/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:31:58 by marvin            #+#    #+#             */
/*   Updated: 2022/01/25 20:35:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(char **av)
{
	int	i;
	int	j;

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

void	bring_front_or_back(t_list *stack, int wanted, int size, char c)
{
	int	med;

	med = size / 2;
	if (wanted <= med)
	{
		while (wanted)
		{
			if (c == 'b')
				rotateb(&stack);
			else if (c == 'a')
				rotatea(&stack);
			wanted--;
		}
	}
	else
	{
		while (wanted != size)
		{
			if (c == 'b')
				rrotateb(&stack);
			else if (c == 'a')
				rrotatea(&stack);
			wanted++;
		}
	}
}

void	handle_3(t_list *a)
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

void	handle_5n4(t_list **a, t_list **b)
{
	int	smallest;
	int	size;

	smallest = smallest_pos (*a);
	size = ft_lstsize (*a);
	bring_front_or_back (*a, smallest, size, 'a');
	pushb (b, a);
	if (size == 5)
	{
		size = ft_lstsize (*a);
		smallest = smallest_pos (*a);
		bring_front_or_back (*a, smallest, size, 'a');
		pushb (b, a);
	}
	handle_3 (*a);
	pusha(a, b);
	if (size == 4)
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
		handle_5n4(&a, &b);
	if (size > 5)
		sort (a, b);
	free_list (a);
}
