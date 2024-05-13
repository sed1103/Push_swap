#include "../Includes/push_swap.h"

void rotate(t_stack **stack)
{
	t_stack *tmp;

	if (!*stack || (*stack && !((*stack)->next)))
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = tmp->next->next;
	tmp->next->next = NULL;
}

void ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}