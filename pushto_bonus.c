/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushto_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:06:38 by marvin            #+#    #+#             */
/*   Updated: 2022/01/25 16:06:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushb(t_list **lst1, t_list **lst2)
{
	t_list	*top;

	if (*lst2)
	{
		top = (*lst2);
		*lst2 = (*lst2)->next;
		top->next = NULL;
		ft_lstadd_front(lst1, top);
		// write (1, "pb\n", 3);
	}
}

void	pusha(t_list **lst1, t_list **lst2)
{
	t_list	*top;

	if (*lst2)
	{
		top = (*lst2);
		*lst2 = (*lst2)->next;
		top->next = NULL;
		ft_lstadd_front (lst1, top);
		// write (1, "pa\n", 3);
	}
}
