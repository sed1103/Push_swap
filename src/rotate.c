/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:38:33 by skirakos          #+#    #+#             */
/*   Updated: 2024/05/20 20:38:34 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || (*stack && !((*stack)->next)))
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = tmp->next->next;
	tmp->next->next = NULL;
}

void	ra(t_stack **stack_a, int n)
{
	rotate(stack_a);
	if (n == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int n)
{
	rotate(stack_b);
	if (n == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int n)
{
	rotate(stack_a);
	rotate(stack_b);
	if (n == 0)
		write(1, "rr\n", 3);
}
