#include "push_swap.h"

void	put_contentback (t_list **head, int lastcon)
{
	t_list	*lastdup;
	t_list	*prevhead;

	prevhead = *head;
	while (*head)
	{
		if ((*head)->content == -1)
		{
			(*head)->content = lastcon;
			*head = prevhead;
			break;
		}
		*head = (*head)->next;
	}
}

t_list	*ft_lstdup (t_list *a)
{
	t_list	*dup;
	t_list	*head;

	dup = ft_lstnew (a->content);
	a = a->next;
	while (a)
	{
		ft_lstadd_back (&dup, ft_lstnew(a->content));
		a = a->next;
	}
	return (dup);
}

t_list	*getlastnode (t_list *a)
{
	while (a)
	{
		if (!a->next)
			return (a);
		a = a->next;
	}
}