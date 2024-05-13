#include "../Includes/push_swap.h"

void	ft_lstclear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (stack && *stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
