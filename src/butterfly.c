/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:25:13 by skirakos          #+#    #+#             */
/*   Updated: 2024/05/20 20:25:14 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	ft_push_back(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	flag;

	flag = size - 1;
	while (*stack_b)
	{
		if ((*stack_b)->index == flag)
		{
			pa(stack_a, stack_b, 0);
			flag -= 1;
			size--;
		}
		else if (get_pos(stack_b, flag) < size / 2 + 1)
			rb(stack_b, 0);
		else if (get_pos(stack_b, flag) >= size / 2 + 1)
			rrb(stack_b, 0);
	}
}

int	get_set(int size)
{
	int	square;
	int	cube;
	int	i;

	i = 0;
	while (i * i <= size)
	{
		if (i * i * i <= size)
			cube = i;
		if (i * i <= size)
			square = i;
		i++;
	}
	return (square + cube);
}

void	ft_butterfly(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		n;
	int		offset;

	offset = get_set(size);
	n = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= n)
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
			n++;
		}
		else if ((*stack_a)->index <= n + offset)
		{
			pb(stack_a, stack_b, 0);
			n++;
		}
		else
			ra(stack_a, 0);
	}
	ft_push_back(stack_a, stack_b, size);
}
