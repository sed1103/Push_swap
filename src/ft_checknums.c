#include "../Includes/push_swap.h"

void ft_check_maxmin(t_stack **stack)
{
	t_stack *tmp1;

	tmp1 = *stack;
	while (tmp1)
	{
		if (tmp1->n > INT_MAX || tmp1->n < INT_MIN)
		{
			ft_lstclear(stack);
			exit(!write(2, "Error\n", 6));
		}
		tmp1 = tmp1->next;
	}
}
void ft_check_duplicate(t_stack **stack)
{
	t_stack *tmp1;
	t_stack *tmp2;

	tmp1 = *stack;

	while (tmp1)
	{
		if (!tmp1->next)
			break;
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->n == tmp2->n)
			{
				ft_lstclear(stack);
				exit(!write(2, "Error\n", 6));
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
