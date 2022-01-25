/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:07:57 by marvin            #+#    #+#             */
/*   Updated: 2022/01/25 16:07:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *str)
{
	int	i;
	int	negative;

	i = 0;
	negative = 0;
	if (str[i] == '-')
		i++;
	if (ft_atoi(str) > 2147483647
		|| ft_atoi(str) < -2147483648)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	free_list(t_list *head)
{
	t_list	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}