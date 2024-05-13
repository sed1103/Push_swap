#include "../Includes/push_swap.h"

int	ft_issorted(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || (*stack && !((*stack)->next)))
		return (1);
	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
