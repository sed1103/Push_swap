/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:38:03 by skirakos          #+#    #+#             */
/*   Updated: 2024/05/20 20:38:04 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
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

void	rra(t_stack **stack_a, int n)
{
	reverse_rotate(stack_a);
	if (n == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int n)
{
	reverse_rotate(stack_b);
	if (n == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int n)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (n == 0)
		write(1, "rrr\n", 4);
}
