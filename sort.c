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

void	push_wanted (t_list **a, t_list **b, int wanted, int med)
{
	int		pos;
	int		size;
	t_list	*head;

	pos = 0;
	head = *b;
	while (*b)
	{
		if ((*b)->content == wanted)
			break;
		pos++;
		*b = (*b)->next;
	}
	*b = head;
	size = ft_lstsize (*b);
	bringb_front_or_back (*b, pos, size, med);
	pusha (a, b);
}

int		not_sorted (t_list *a)
{
	t_list	*head;
	int pos;
	int		sorted;

	sorted = 1;
	pos = 0;
	head = a;
	while (a->next)
	{
		if (a->content > a->next->content)
		{
			sorted = 0;
			break;
		}
		pos++;
		a = a->next;
	}
	return (sorted);
}

int		is_there (int content, t_list *b)
{
	while (b)
	{
		if (b->content == content)
			return (1);
		b = b->next;
	}
	return (0);
}

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

void	put_back (t_list **a, t_list **b, int lastcon)
{
	t_list	*lastnode;
	int		med;

	lastnode = getlastnode(*a);
	while (*b)
	{
		med = ft_lstsize (*b) / 2;
		if (is_there ((*a)->content - 1, *b))
		{
			if ((*b)->content == (*a)->content - 1)
				pusha (a, b);
			else if ((*b)->content < (*a)->content
			&& (*b)->content > lastnode->content)
			{
				pusha (a, b);
				rotatea (a);
			}
			else
				push_wanted (a, b, (*a)->content - 1, med);
		}
		else
			rrotatea (a);
		lastnode = getlastnode(*a);
	}
	put_contentback (a, lastcon);
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
	pushed = ((size - 5) / 4) + 1;
	min = smallest (*a);
	max = min + (pushed - 1);
	elements_med = (max + min) / 2;
	while (i < pushed)
	{
		med = size / 2;
		from_set = set_pos(*a, min, max);
		bringa_front_or_back (*a, from_set, size, med);
		pushb (b, a);
		if ((*b)->content < elements_med && ft_lstsize(*b) >= 2)
			rotateb (b);
		size = ft_lstsize(*a);
		i++;
	}
}

t_list	*put1 (t_list *head)
{
	t_list	*lastdup;
	while (head)
	{
		if (head->next == NULL)
		{
			lastdup = ft_lstdup (head);
			head->content = -1;
		}
		head = head->next;
	}
	return (lastdup);
}
// void    print_stack(t_list *stack)
// {
// 	while (stack)
// 	{
// 		printf ("%d\n", stack->content);
// 		stack = stack->next;
// 	}
// }
void	sort1 (t_list *a, t_list *b)
{
	int size;
	t_list *lastdup;

	// printf ("Function 1\n");
	indexing (a);
	// print_stack(a);
	// print_stack(a);
	// print_stack(a);
	size = ft_lstsize(a);
	// printf ("Function 2\n");
	while (size > 5)
	{
		push_elements (&a, &b);
		size = ft_lstsize(a);
	}
	// printf ("Function 3\n");
	handle_5n4 (&a, &b);
	// print_stack(a);
	// printf ("Function 3\n");
	lastdup = put1 (a);
	// printf ("Function 4\n");
	put_back (&a, &b, lastdup->content);
	// printf ("Function 4\n");
	while (!not_sorted(a))
		rrotatea(&a);
	// print_stack(a);
	// print_stack (a);
}
