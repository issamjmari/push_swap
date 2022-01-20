#include "push_swap.h"

void	pushb (t_list **lst1, t_list **lst2)
{
	t_list *top;

	if (*lst2)
	{
		top = (*lst2);
		*lst2 = (*lst2)->next;
		top->next = NULL;
		ft_lstadd_front (lst1 ,top);
	}
}
void	pusha (t_list **lst1, t_list **lst2)
{
	t_list *top;

	if (*lst2)
	{
		top = (*lst2);
		*lst2 = (*lst2)->next;
		top->next = NULL;
		ft_lstadd_front (lst1 ,top);
	}
}