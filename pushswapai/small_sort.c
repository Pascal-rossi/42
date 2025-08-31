#include "push_swap_utils.h"

void	sort_3(t_node **head)
{
	int	first;
	int	second;
	int	third;

	if (!head || !*head || stack_size(head) < 3)
		return ;
	first = (*head)->value;
	second = (*head)->next->value;
	third = (*head)->next->next->value;
	if (first > second && second < third && first < third)
		sa(head, true);
	else if (first > second && second > third)
	{
		sa(head, true);
		rra(head, true);
	}
	else if (first > second && second < third && first > third)
		ra(head, true);
	else if (first < second && second > third && first < third)
	{
		sa(head, true);
		ra(head, true);
	}
	else if (first < second && second > third && first > third)
		rra(head, true);
}