/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:30:21 by marvin            #+#    #+#             */
/*   Updated: 2022/01/25 15:30:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_pos(t_list *stack)
{
	int	position;
	int	smallest;
	int	ret;

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
