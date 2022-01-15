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
	print_stack (a);
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
