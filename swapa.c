#include "push_swap.h"
void	swapboth (t_list *lst1, t_list *lst2)
{
	int	size1;
	int size2;
	int temp1;
	int temp2;

	size1 = ft_lstsize (lst1);
	size2 = ft_lstsize (lst2);
	if (size1 >= 2 && size2 >= 2)
	{
		temp1 = lst1->next->content;
		lst1->next->content = lst1->content;
		lst1->content = temp1;
		temp2 = lst2->next->content;
		lst2->next->content = lst2->content;
		lst2->content = temp2;
	}
}
void	swaplst (t_list *lst)
{
	int size;
	int	temp;

	size = ft_lstsize (lst);
	if (size >= 2)
	{
		temp = lst->next->content;
		lst->next->content = lst->content;
		lst->content = temp;
	}
}