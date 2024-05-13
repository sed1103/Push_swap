#include "../Includes/push_swap.h"

t_stack	*ft_lstnew(long long content)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->n = content;
	stack->next = NULL;
	return (stack);
}

void add_stack(t_stack **tmp, char **res, t_stack **stack)
{
	int	i;

	i = 0;
	while (res[i])
	{
		//printf("%d \n", ft_atoi(str[i]));
		(*tmp)->next = ft_lstnew(ft_atoi(res[i]));
		if (!(*tmp))
		{
			ft_lstclear(stack);
			free_res(res, i);
			exit(!write(2, "Error\n", 6));
		}
		*tmp = (*tmp)->next;
		free(res[i++]);
	}
}

void stack_init(t_stack **stack, char **str)
{
	int		i;
	char	**res;
	t_stack	*begin;
	t_stack *tmp;

	begin = *stack;
	i = 1;
	while (str[i])
	{
		res = ft_split(str[i++], " ");
		if (!res)
			return ;
		add_stack(&begin, res, stack);
		free(res);
		res = NULL;
	}
	tmp = *stack;
	(*stack) = (*stack)->next;
	free(tmp);
	ft_check_maxmin(stack);
	ft_check_duplicate(stack);
}
