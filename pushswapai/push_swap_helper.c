#include "push_swap_utils.h"

void	find_target_nodes(t_node **heada, t_node **headb)
{
	t_node	*current_b;
	t_node	*current_a;
	t_node	*target;
	long	best_match;

	if (!headb || !*headb || !heada)
		return ;
	current_b = *headb;
	while (current_b)
	{
		best_match = LONG_MAX;
		current_a = *heada;
		target = NULL;
		while (current_a)
		{
			if (current_a->value > current_b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			current_b->target_node = find_min(heada);
		else
			current_b->target_node = target;
		current_b = current_b->next;
	}
}