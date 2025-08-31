#include "push_swap_utils.h"

void	choose_sort(t_node **heada, t_node **headb)
{
	int	size;

	if (!heada || !*heada)
		return ;
	size = stack_size(heada);
	if (size == 2)
	{
		if ((*heada)->value > (*heada)->next->value)
			sa(heada, true);
	}
	else if (size == 3)
		sort_3(heada);
	else if (size == 4)
		sort_4(heada, headb);
	else if (size == 5)
		sort_5(heada, headb);
	else
		big_sort(heada, headb);
}

bool	is_sorted(t_node **head)
{
	t_node	*current;

	if (!head || !*head)
		return (true);
	current = *head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}