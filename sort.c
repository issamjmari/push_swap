#include "push_swap.h"
int getpos (t_list *head, t_list *a)
{
	int pos;

	pos = 0;
	while (head)
	{
		if (head == a)
			return pos;
		head = head->next;
		pos++;
	}
	return 0;
}
void handlepos (t_list **a, t_list **b)
{
	int smaller;
	int 	pos;
	t_list *head;

	head = *a;
	while (*a)
	{
		smaller = checksmaller (*a);
		while (*a)
		{
			if (smaller == (*a)->content)
			{
				pos = getpos (head, *a);
				while (pos != 0)
				{
					rotatea (&head);
					pos--;
				}
				pushb (b, a);
				while (*b)
				{
					printf ("%d\n", (head)->content);
					head = (head)->next;
				}
				break;
			}
			*a = (*a)->next;
		}
		// *a = head;
	}
}
void sort (t_list *a, t_list *b)
{
	t_list	*head;
	int		med;
	int		smaller;

	med = ft_lstsize (a) / 2;
	handlepos (&a, &b);
}