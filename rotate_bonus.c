/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:05:58 by marvin            #+#    #+#             */
/*   Updated: 2022/01/25 16:05:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotateb(t_list **lst)
{
	int		current;
	t_list	*last;
	t_list	*head;

	current = (*lst)->content;
	head = *lst;
	last = ft_lstlast (*lst);
	(*lst)->content = (*lst)->next->content;
	*lst = (*lst)->next;
	while ((*lst)->next)
	{
		(*lst)->content = (*lst)->next->content;
		(*lst) = (*lst)->next;
	}
	(*lst)->content = current;
	*lst = head;
	write (1, "rb\n", 3);
}

void	rrotateb(t_list **lst)
{
	int		prevcon;
	int		lastcon;
	int		temp;
	t_list	*last;
	t_list	*head;

	last = ft_lstlast (*lst);
	lastcon = last->content;
	prevcon = (*lst)->content;
	head = (*lst);
	(*lst) = (*lst)->next;
	while (*lst)
	{
		temp = (*lst)->content;
		(*lst)->content = prevcon;
		prevcon = temp;
		(*lst) = (*lst)->next;
	}
	head->content = lastcon;
	*lst = head;
	write (1, "rrb\n", 4);
}

void	rotatea(t_list **lst)
{
	int		current;
	t_list	*last;
	t_list	*head;

	current = (*lst)->content;
	head = *lst;
	last = ft_lstlast (*lst);
	(*lst)->content = (*lst)->next->content;
	*lst = (*lst)->next;
	while ((*lst)->next)
	{
		(*lst)->content = (*lst)->next->content;
		(*lst) = (*lst)->next;
	}
	(*lst)->content = current;
	*lst = head;
	write (1, "ra\n", 3);
}

void	rrotatea(t_list **lst)
{
	int		prevcon;
	int		lastcon;
	int		temp;
	t_list	*last;
	t_list	*head;

	last = ft_lstlast (*lst);
	lastcon = last->content;
	prevcon = (*lst)->content;
	head = (*lst);
	(*lst) = (*lst)->next;
	while (*lst)
	{
		temp = (*lst)->content;
		(*lst)->content = prevcon;
		prevcon = temp;
		(*lst) = (*lst)->next;
	}
	head->content = lastcon;
	*lst = head;
	write (1, "rra\n", 4);
}
