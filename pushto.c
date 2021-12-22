#include "push_swap.h"
void	del (int content)
{
	int *a;

	a = &content;
	*a = 0;
}
void	push (t_list **lst1, t_list *lst2)
{
	if (*lst1 && lst2)
	{
		lst2->next = *lst1;
		*lst1 = lst2;
	}
	else
		*lst1 = lst2;
}