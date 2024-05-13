#include "../Includes/push_swap.h"

void reverse_rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack	*begin;

	if (!*stack || (*stack && !((*stack)->next)))
		return ;
	tmp = *stack;
	begin = *stack;
	while (tmp->next)
	{
		begin = tmp;
		tmp = tmp->next;
	}
	begin->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}