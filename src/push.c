/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:37:26 by skirakos          #+#    #+#             */
/*   Updated: 2024/05/20 20:37:27 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	push(t_stack **first, t_stack **second)
{
	t_stack	*tmp;

	if (!(second) || !(first) || !(*second))
		return ;
	tmp = *second;
	*second = (*second)->next;
	tmp->next = *first;
	*first = tmp;
}

void	pa(t_stack **first, t_stack **second, int n)
{
	push(first, second);
	if (n == 0)
		write(1, "pa\n", 3);
}

void	pb(t_stack **first, t_stack **second, int n)
{
	push(second, first);
	if (n == 0)
		write(1, "pb\n", 3);
}
