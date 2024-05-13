#include "../Includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc == 1)
		return (0);
	ft_validation(argc, argv);
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (1);
	stack_a->next = NULL;
	stack_b = NULL;
	stack_init(&stack_a, argv);
	ft_sort(&stack_a, &stack_b);
}
	
	
	
