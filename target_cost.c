#include "push_swap_utils.h"

void	find_target_nodes(t_node **heada, t_node **headb)
{
	t_node	*current_b;
	t_node	*current_a;
	t_node	*target;
	long	best_match;

	if (!headb || !*headb)
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

void	calculate_costs(t_node **heada, t_node **headb)
{
	t_node	*current;
	int		size_a;
	int		size_b;

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