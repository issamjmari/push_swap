/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:31:16 by marvin            #+#    #+#             */
/*   Updated: 2022/01/25 15:31:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_pos(t_list *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->content >= min && a->content <= max)
			return (pos);
		pos++;
		a = a->next;
	}
}

int	current_pos(int size, int current, t_list *dup)
{
	int	pos;

	pos = 0;
	while (dup)
	{
		if (dup->content >= current)
			pos++;
		dup = dup->next;
	}
	pos = size - pos;
	return (pos);
}

int	not_sorted(t_list *a)
{
	t_list	*head;
	int		pos;
	int		sorted;

	sorted = 1;
	pos = 0;
	head = a;
	while (a->next)
	{
		if (a->content > a->next->content)
		{
			sorted = 0;
			break ;
		}
		pos++;
		a = a->next;
	}
	return (sorted);
}

int	is_there(int content, t_list *b)
{
	while (b)
	{
		if (b->content == content)
			return (1);
		b = b->next;
	}
	return (0);
}

int	put1(t_list *head)
{
	t_list	*lastdup;
	int		lastcon;

	while (head)
	{
		if (head->next == NULL)
		{
			lastcon = head->content;
			head->content = -1;
		}
		head = head->next;
	}
	return (lastcon);
}
