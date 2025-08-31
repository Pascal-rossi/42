#include "push_swap_utils.h"

void	big_sort(t_node **heada, t_node **headb)
{
	int	size;

	if (!heada || !*heada)
		return ;
	size = stack_size(heada);
	while (size > 3)
	{
		pb(heada, headb, true);
		size--;
	}
	sort_3(heada);
	while (*headb)
	{
		init_nodes(heada, headb);
		move_nodes(heada, headb, find_cheapest(headb));
	}
	final_rotation(heada);
}

void	init_nodes(t_node **heada, t_node **headb)
{
	set_positions(heada);
	set_positions(headb);
	find_target_nodes(heada, headb);
	calculate_costs(heada, headb);
	set_cheapest(headb);
}

void	set_positions(t_node **head)
{
	int		pos;
	t_node	*current;

	if (!head || !*head)
		return ;
	pos = 0;
	current = *head;
	while (current)
	{
		current->index = pos;
		current->above_median = (pos <= stack_size(head) / 2);
		current = current->next;
		pos++;
	}
}