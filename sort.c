#include "push_swap.h"

int	set_pos (t_list *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->content >= min && a->content <= max)
			return (pos);
		pos++;
		a = a->next;
	}
}
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

t_list	*getlastnode (t_list *a)
{
	while (a)
	{
		if (!a->next)
			return (a);
		a = a->next;
	}
}

void	put_back (t_list **a, t_list **b)
{
	t_list	*lastnode;

	lastnode = getlastnode(*a);
	while (*b)
	{
		if (dispo ((*a)->content - 1, *b))
		{
			if ((*b)->content == (*a)->content - 1)
				pusha (a, b);
			else if ((*b)->content < (*a)->content
			&& (*b)->content > lastnode->content)
			{
				pusha (a, b);
				rrotatea (a);
			}
		}
		else
			rrotatea (a);
	}
}

void	push_elements (t_list **a, t_list **b)
{
	int min;
	int max;
	int pushed;
	int med;
	int elements_med;
	int size;
	int from_set;
	int i;

	i = 0;

	size = ft_lstsize(*a);
	pushed = ((size - 5) / 3) + 1;
	min = smallest (*a);
	max = min + (pushed - 1);
	elements_med = (max + min) / 2;
	while (i < pushed)
	{
		med = size / 2;
		from_set = set_pos(*a, min, max);
		if (from_set <= med)
		{
			while (from_set)
			{
				rotatea(a);
				from_set--;
			}
		}
		else if (from_set > med)
		{
			while (from_set != size)
			{
				rrotatea (a);
				from_set++;
			}
		}
		pushb (b, a);
		if ((*b)->content < elements_med && ft_lstsize(*b) >= 2)
			rotateb (b);
		size = ft_lstsize(*a);
		i++;
	}
}

void	put1 (t_list *head)
{
	while (head)
	{
		if (head->next == NULL)
			head->content = -1;
		head = head->next;
	}
}

void	sort1 (t_list *a, t_list *b)
{
	int size;
	int max;
	int min;
	int pushed;
	t_list *head;

	indexing (a);
	size = ft_lstsize(a);
	while (size > 5)
	{
		push_elements (&a, &b);
		size = ft_lstsize(a);
	}
	handle_5n4 (&a, &b, size);
	put1 (a);
	put_back (&a, &b);
}
