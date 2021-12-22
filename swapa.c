#include "push_swap.h"
t_list	*swaplst (t_list *lst)
{
	int	temp;


	temp = lst->next->content;
	lst->next->content = lst->content;
	lst->content = temp;
	return (lst);
}