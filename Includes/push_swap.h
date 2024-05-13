#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_stack
{
	long long		n;
	int				index;
	struct s_stack	*next;
}	t_stack;

void 		ft_validation(int argc, char **argv);
long long	ft_atoi(char *str);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
void 	ft_countdigit(char *str);
void 	check_null(char **str);
void 	stack_init(t_stack **stack, char **str);
char	**ft_split(char const *s, char *c);
void	free_res(char **res, int i);
void	ft_lstclear(t_stack **stack);
void ft_check_duplicate(t_stack **stack);
void ft_check_maxmin(t_stack **stack);
int	ft_issorted(t_stack **stack);
int	find_min(t_stack **stack);
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void	sort_3n(t_stack **stack);
int		get_pos(t_stack **stack, int index);
void	set_index(t_stack **stack);
void	sort_5n(t_stack **stack_a, t_stack **stack_b, int size);
void pa(t_stack **first, t_stack **second);
void pb(t_stack **first, t_stack **second);
void ft_sort(t_stack **stack_a, t_stack **stack_b);
void ft_butterfly(t_stack **stack_a, t_stack **stack_b, int size);

#endif