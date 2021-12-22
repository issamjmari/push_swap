#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "Libft/libft.h"
t_list	*rotate(t_list *lst);
void	swaplst (t_list *lst);
void	push (t_list **lst1, t_list **lst2);
void	swapboth (t_list *lst1, t_list *lst2);
#endif