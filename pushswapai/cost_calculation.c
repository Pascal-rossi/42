#include "push_swap_utils.h"

void	calculate_costs(t_node **heada, t_node **headb)
{
	t_node	*current;
	int		size_a;
	int		size_b;

	if (!headb || !*headb || !heada)
		return ;
	size_a = stack_size(heada);
	size_b = stack_size(headb);
	current = *headb;
	while (current)
	{
		current->push_cost = current->index;
		if (!current->above_median)
			current->push_cost = size_b - current->index;
		if (current->target_node->above_median)
			current->push_cost += current->target_node->index;
		else
			current->push_cost += size_a - current->target_node->index;
		current = current->next;
	}
}

void	set_cheapest(t_node **headb)
{
	t_node	*current;
	t_node	*cheapest;
	int		cheapest_cost;

	if (!headb || !*headb)
		return ;
	current = *headb;
	cheapest = current;
	cheapest_cost = current->push_cost;
	while (current)
	{
		current->cheapest = false;
		if (current->push_cost < cheapest_cost)
		{
			cheapest_cost = current->push_cost;
			cheapest = current;
		}
		current = current->next;
	}
	if (cheapest)
		cheapest->cheapest = true;
}

t_node	*find_cheapest(t_node **headb)
{
	t_node	*current;

	if (!headb || !*headb)
		return (NULL);
	current = *headb;
	while (current)
	{
		if (current->cheapest)
			return (current);
		current = current->next;
	}
	return (NULL);
}