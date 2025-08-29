#include "push_swap_utils.h"

void	big_sort(t_node **heada, t_node **headb)
{

	if (!heada || !*heada)
		return ;
	
	// Push all except 3 to stack B
	while (stack_size(heada) > 3)
	{
		pb(heada, headb, true);
		if (!validate_stack(*heada) || !validate_stack(*headb))
		{
			printf("STACK CORRUPTION DETECTED!\n");
			return ;
		}
	}	
	
	// Sort the remaining 3 in stack A
	sort_3(heada);
	
	// Main sorting loop
	while (*headb)
	{
		// Initialize nodes
		init_nodes(heada, headb);
		
		// Find cheapest node to push
		t_node	*cheapest = find_cheapest(headb);
		
		// Move nodes to correct positions
		move_nodes(heada, headb, cheapest);
	}
	
	// Final rotation to get min value to top
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