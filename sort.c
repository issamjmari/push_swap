/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:32:19 by marvin            #+#    #+#             */
/*   Updated: 2022/01/25 20:41:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list *a)
{
	t_list	*ahead;
	t_list	*dup;
	t_list	*duphead;
	int		size;

	dup = ft_lstdup (a);
	size = ft_lstsize (dup);
	duphead = dup;
	ahead = a;
	while (dup)
	{
		a->content = current_pos (size, dup->content, duphead);
		dup = dup->next;
		a = a->next;
	}
	free_list (duphead);
}

void	push_wanted(t_list **a, t_list **b, int wanted, int med)
{
	int		pos;
	int		size;
	t_list	*head;

	pos = 0;
	head = *b;
	while (*b)
	{
		if ((*b)->content == wanted)
			break ;
		pos++;
		*b = (*b)->next;
	}
	*b = head;
	size = ft_lstsize(*b);
	bring_front_or_back (*b, pos, size, 'b');
	pusha (a, b);
}

void	put_back(t_list **a, t_list **b, int lastcon)
{
	t_list	*lastnode;
	int		med;

	lastnode = getlastnode(*a);
	while (*b)
	{
		med = ft_lstsize (*b) / 2;
		if (is_there ((*a)->content - 1, *b))
		{
			if ((*b)->content == (*a)->content - 1)
				pusha (a, b);
			else if ((*b)->content < (*a)->content
				&& (*b)->content > lastnode->content)
			{
				pusha (a, b);
				rotatea (a);
			}
			else
				push_wanted (a, b, (*a)->content - 1, med);
		}
		else
			rrotatea (a);
		lastnode = getlastnode(*a);
	}
	put_contentback (a, lastcon);
}

void	push_elements(t_list **a, t_list **b)
{
	int	min;
	int	max;
	int	pushed;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(*a);
	pushed = ((size - 5) / 4) + 1;
	min = smallest (*a);
	max = min + (pushed - 1);
	while (i < pushed)
	{
		bring_front_or_back (*a, set_pos(*a, min, max), size, 'a');
		pushb (b, a);
		if ((*b)->content < (max + min) / 2 && ft_lstsize(*b) >= 2)
			rotateb (b);
		size = ft_lstsize(*a);
		i++;
	}
}

void	sort(t_list *a, t_list *b)
{
	int		size;
	t_list	*lastdup;

	indexing (a);
	size = ft_lstsize(a);
	while (size > 5)
	{
		push_elements (&a, &b);
		size = ft_lstsize(a);
	}
	handle_5n4 (&a, &b);
	put_back (&a, &b, put1(a));
	while (!not_sorted(a))
		rrotatea(&a);
}
