#include "push_swap.h"

t_list	*fillwithmax (t_list **a, int smallest, int size, t_list **b)
{
	static int	firsttime;
	int i;
	t_list	*head;

	i = 0;
	head = *a;
	if (!firsttime)
	{
		while ((*a)->content != 2147483647)
			(*a) = (*a)->next;
		
	}
	*a = head;
	while (i != smallest)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->content = 2147483647;
	*a = head;
}

void	indexing (t_list *a, t_list *b)
{
	int smallest;
	int *arr;
	int	size;
	int	i;
	t_list	*head;

	i = 0;
	head = a;
	size = ft_lstsize (a);
	arr = (int *) malloc (size * sizeof (int));
	while (i < size)
	{
		smallest = smallest_pos (a);
		arr[smallest] = i;
		fillwithmax (&a, smallest, size);
		i++;
 	}
	i = 0;
	while (a)
	{
		a->content = arr[i];
		a = a->next;
		i++;
	}
	a = head;
	print_stack(a);
}

int	getpos (t_list *head, int a)
{
	int pos;

	pos = 0;
	while (head)
	{
		if (head->content == a)
			return pos;
		pos++;
		head = head->next;
	}
	return 0;
}

void	sort(t_list *a, t_list *b, int size) 
{
	int	smallest;
	int	med;

	while (a != NULL) {
		smallest = smallest_pos(a);
		size = ft_lstsize (a);
		med = size / 2;
		if (smallest <= med) 
		{
			while (smallest)
			{
				rotatea(&a);
				smallest--;
			}
		}
		else if (smallest >= med)
		{
			while (smallest != size)
			{
				rrotatea (&a);
				smallest++;
			}
		}
		pushb(&b, &a);
	}
	while (b)
		pusha(&a, &b);
}

void	sort1 (t_list *a, t_list *b)
{
	int max;
	int min;
	int pushed;
	int mid;

	indexing (a);
}
