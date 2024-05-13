#include "../Includes/push_swap.h"

int		get_pos(t_stack **stack, int index)
{
	t_stack	*tmp;
	int		pos;

	tmp = *stack;
	pos = 0;
	while (tmp && tmp->index != index)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	set_index(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	tmp = *stack;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp)
	{
		current = *stack;
		while (current)
		{
			if (current->n < tmp->n)
				tmp->index += 1;
			current = current->next;
		}
		tmp = tmp->next;
	}
}

void	sort_5n(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	flag;

	flag = 0;
	while (size > 3 )
	{
		if ((*stack_a)->index == flag)
		{
			pb(stack_a, stack_b);
			size--;
			flag += 1;
		}
		else if (get_pos(stack_a, flag) < size / 2 + 1)
			ra(stack_a);
		else if (get_pos(stack_a, flag) >= size / 2 + 1)
			rra(stack_a);
	}
	if (ft_issorted(stack_a) == 0)
		sort_3n(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_3n(t_stack **s)
{
	if ((*s)->n < (*s)->next->n && (*s)->n < (*s)->next->next->n)
	{
		sa(*s);
		ra(s);
	}
	else if ((*s)->n < (*s)->next->n && (*s)->n > (*s)->next->next->n)
		rra(s);
	else if ((*s)->n > (*s)->next->n && (*s)->n < (*s)->next->next->n)
		sa(*s);
	else if ((*s)->n > (*s)->next->n && (*s)->n > (*s)->next->next->n
		&& (*s)->next->n < (*s)->next->next->n)
		ra(s);
	else
	{
		ra(s);
		sa(*s);
	}
}

void ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	t_stack	*tmp;

	tmp = *stack_a;
	size = 0;
	if (ft_issorted(stack_a) == 1)
		return ;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	set_index(stack_a);
	if (size == 2)
		sa(*stack_a);
	else if (size == 3)
		sort_3n(stack_a);
	else if (size <= 5)
		sort_5n(stack_a, stack_b, size);
	else
		ft_butterfly(stack_a, stack_b, size);
}