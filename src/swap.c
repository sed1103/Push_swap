/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:38:49 by skirakos          #+#    #+#             */
/*   Updated: 2024/05/20 20:39:12 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !(stack->next))
		return ;
	tmp = stack->n;
	stack->n = stack->next->n;
	stack->next->n = tmp;
}

void	ss(t_stack *stack_a, t_stack *stack_b, int n)
{
	swap(stack_a);
	swap(stack_b);
	if (n == 0)
		write(1, "ss\n", 3);
}

void	sa(t_stack *stack_a, int n)
{
	swap(stack_a);
	if (n == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, int n)
{
	swap(stack_b);
	if (n == 0)
		write(1, "sb\n", 3);
}
