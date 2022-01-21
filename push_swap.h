#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h" 
void	sort1 (t_list *a, t_list *b);
int     smallest_pos(t_list *stack);
void	rotatea(t_list **lst);
void	rotateb(t_list **lst);
void	rrotateb(t_list **lst);
void	swapa (t_list **lst);
void	swapb (t_list **lst);
void	pusha (t_list **lst1, t_list **lst2);
void	pushb (t_list **lst1, t_list **lst2);
void	swapboth (t_list **lst1, t_list **lst2);
void	rrotatea (t_list **lst);
void	rrotatea (t_list **lst);
void	countsort (int *n, int size);
void 	sort (t_list *a, t_list *b, int size);
void	handle_5n4 (t_list **a, t_list **b);
void    print_stack(t_list *stack);
int	    smallest(t_list *stack);
void	bringa_front_or_back (t_list *stack, int wanted, int size, int med);
void	bringb_front_or_back (t_list *stack, int wanted, int size, int med);
#endif
