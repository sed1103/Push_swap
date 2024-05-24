/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <skirakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:27:50 by skirakos          #+#    #+#             */
/*   Updated: 2024/05/24 15:53:05 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "../Includes/get_next_line.h"

int	s_sort(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (str[1] == 'a' && str[2] == '\n' && str[3] == '\0')
		sa(*stack_a, 1);
	else if (str[1] == 'b' && str[2] == '\n')
		sb(*stack_b, 1);
	else if (str[1] == 's' && str[2] == '\n')
		ss(*stack_a, *stack_b, 1);
	else
		return (0);
	return (1);
}

int	p_sort(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (str[1] == 'a' && str[2] == '\n')
		pa(stack_a, stack_b, 1);
	else if (str[1] == 'b' && str[2] == '\n')
		pb(stack_a, stack_b, 1);
	else
		return (0);
	return (1);
}

int	r_sort(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (str[1] == 'a' && str[2] == '\n' && str[3] == '\0')
		ra(stack_a, 1);
	else if (str[1] == 'b' && str[2] == '\n' && str[3] == '\0')
		rb(stack_b, 1);
	else if (str[1] == 'r' && str[2] == '\n' && str[3] == '\0')
		rr(stack_a, stack_b, 1);
	else if (str[1] == 'r' && str[2] == 'a' && str[3] == '\n')
		rra(stack_a, 1);
	else if (str[1] == 'r' && str[2] == 'b' && str[3] == '\n')
		rrb(stack_b, 1);
	else if (str[1] == 'r' && str[2] == 'r' && str[3] == '\n')
		rrr(stack_a, stack_b, 1);
	else
		return (0);
	return (1);
}

int	sort(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;
	int		flag;

	str = get_next_line(0);
	while (str)
	{
		if (str[0] == 's')
			flag = s_sort(stack_a, stack_b, str);
		else if (str[0] == 'r')
			flag = r_sort(stack_a, stack_b, str);
		else if (str[0] == 'p')
			flag = p_sort(stack_a, stack_b, str);
		else
			flag = 0;
		free(str);
		if (flag == 0)
			return (0);
		str = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	ft_validation(argv);
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (1);
	stack_a->next = NULL;
	stack_b = NULL;
	stack_init(&stack_a, argv);
	if (sort(&stack_a, &stack_b) == 0)
	{
		ft_lstclear(&stack_a);
		exit(1 && write(2, "Error\n", 6));
	}
	if (ft_issorted(&stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a);
	if (stack_b != NULL)
		ft_lstclear(&stack_b);
	return (0);
}
