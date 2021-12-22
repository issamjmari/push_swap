#include "push_swap.h"
t_list	*rotate(t_list *lst)
{
	int		prevcon;
	int		lastcon;
	int		temp;
	t_list	*last;
	t_list	*head;

	last = ft_lstlast (lst);
	lastcon = last->content;
	prevcon = lst->content;
	head = lst;
    lst = lst->next;
    while (lst) 
	{
        temp = lst->content;
        lst->content = prevcon;
        prevcon = temp;
        lst = lst->next;
    }
	head->content = lastcon;
	return (head);
}