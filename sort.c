#include "push_swap.h"

int	current_pos (int size, int current, t_list *dup)
{
	int pos;

	pos = 0;
	while (dup)
	{
		if (dup->content >= current)
			pos++;
		dup = dup->next;
	}
	pos = size - pos;
	return (pos);
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

void	indexing (t_list *a)
{
	t_list	*ahead;
	t_list	*dup;
	t_list	*duphead;
	int		size;

	dup = ft_lstdup (a);
	size = ft_lstsize (dup);
	duphead = dup;
	ahead = a;
	while (dup)
	{
		a->content = current_pos (size, dup->content, duphead);
		dup = dup->next;
		a = a->next;
	}
	a = ahead;
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

		smallest = smallest_pos(a);
		size = ft_lstsize (a);
		med = size / 2;
		pushb(&b, &a);
}

void	push_elements (t_list **a, t_list **b, int size)
{
	int min;
	int max;
	int pushed;
	int med;
	int	i;

	i = 0;
	pushed = ((size - 5) / 3) + 1;
	med = (max + min) / 2;
	while (i < pushed)
	{
		min = smallest_pos (*a);
		if (min <= med) 
		{
			while (min)
			{
				rotatea(a);
				min--;
			}
		}
		else if (min >= med)
		{
			while (min != size)
			{
				rrotatea (a);
				min++;
			}
		}
		pushb (b, a);
		i++;
	}
}

void	sort1 (t_list *a, t_list *b)
{
	int size;
	int max;
	int min;
	int pushed;

	indexing (a);
	size = ft_lstsize(a);
	print_stack (a);
	printf ("--\n-----BEFORE---\n--------\n");
	while (size > 5)
	{
		push_elements (&a, &b, size);
		size = ft_lstsize(a);
	}
	print_stack (a);
}
