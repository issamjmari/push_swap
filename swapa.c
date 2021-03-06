/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:28:26 by marvin            #+#    #+#             */
/*   Updated: 2022/01/25 15:30:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapb(t_list **lst)
{
	int	size;
	int	temp;

	size = ft_lstsize (*lst);
	if (size >= 2)
	{
		temp = (*lst)->next->content;
		(*lst)->next->content = (*lst)->content;
		(*lst)->content = temp;
	}
	write (1, "sb\n", 3);
}

void	swapa(t_list **lst)
{
	int	size;
	int	temp;

	size = ft_lstsize (*lst);
	if (size >= 2)
	{
		temp = (*lst)->next->content;
		(*lst)->next->content = (*lst)->content;
		(*lst)->content = temp;
	}
	write (1, "sa\n", 3);
}

void	swapboth(t_list **lst1, t_list **lst2)
{
	int	size1;
	int	size2;
	int	temp1;
	int	temp2;

	size1 = ft_lstsize (*lst1);
	size2 = ft_lstsize (*lst2);
	if (size1 >= 2)
		swapa (lst1);
	if (size2 >= 2)
		swapb (lst2);
	write (1, "ss\n", 3);
}
