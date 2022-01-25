/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:30:05 by marvin            #+#    #+#             */
/*   Updated: 2022/01/25 16:31:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"

void	put_contentback(t_list **head, int lastcon);
int		is_int(char *str);
int		smallest_pos(t_list *stack);
int		smallest(t_list *stack);
t_list	*ft_lstdup(t_list *a);
t_list	*getlastnode(t_list *a);
int		put1(t_list *head);
int		is_there(int content, t_list *b);
int		not_sorted(t_list *a);
int		current_pos(int size, int current, t_list *dup);
int		set_pos(t_list *a, int min, int max);
int		smallest_pos(t_list *stack);
void	rotatea(t_list **lst);
void	rotateb(t_list **lst);
void	rrotateb(t_list **lst);
void	swapa(t_list **lst);
void	swapb(t_list **lst);
void	pusha(t_list **lst1, t_list **lst2);
void	pushb(t_list **lst1, t_list **lst2);
void	swapboth(t_list **lst1, t_list **lst2);
void	rrotatea(t_list **lst);
void	rrotatea(t_list **lst);
void	countsort(int *n, int size);
void	sort(t_list *a, t_list *b);
void	handle_5n4(t_list **a, t_list **b);
void	print_stack(t_list *stack);
int		smallest(t_list *stack);
void	bring_front_or_back(t_list *stack, int wanted, int size, char c);
#endif
