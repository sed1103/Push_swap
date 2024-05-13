#include "../Includes/push_swap.h"

void push(t_stack **first, t_stack **second)
{
	t_stack *tmp;

	if (!(second) || !(first) || !(*second))
		return ;
	tmp = *second;
	*second = (*second)->next;
	tmp->next = *first;
	*first = tmp;
}

void pa(t_stack **first, t_stack **second)
{
	push(first, second);
	write(1, "pa\n", 3);
}

void pb(t_stack **first, t_stack **second)
{
	push(second, first);
	write(1, "pb\n", 3);
}
