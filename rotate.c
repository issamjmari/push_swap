#include "push_swap.h"
void	rotate (t_list **lst)
{
	int	current;
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
}
void	rrotate(t_list **lst)
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
}