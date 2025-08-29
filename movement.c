#include "push_swap_utils.h"

void	move_nodes(t_node **heada, t_node **headb, t_node *cheapest)
{
	rotate_both(heada, headb, cheapest);
	rotate_a_to_target(heada, cheapest->target_node);
	rotate_b_to_top(headb, cheapest);
	pa(heada, headb, true);
}

void	rotate_both(t_node **heada, t_node **headb, t_node *cheapest)
{
	while (*heada != cheapest->target_node && *headb != cheapest)
	{
		if (cheapest->above_median && cheapest->target_node->above_median)
			rr(heada, headb);
		else if (!cheapest->above_median && !cheapest->target_node->above_median)
			rrr(heada, headb, true);
		else
			break ;
	}
}

void	rotate_a_to_target(t_node **heada, t_node *target)
{
	while (*heada != target)
	{
		if (target->above_median)
			ra(heada, true);
		else
			rra(heada, true);
	}
}

void	rotate_b_to_top(t_node **headb, t_node *cheapest)
{
	while (*headb != cheapest)
	{
		if (cheapest->above_median)
			rb(headb, true);
		else
			rrb(headb, true);
	}
}

void	final_rotation(t_node **heada)
{
	t_node	*min_node;

	if (!heada || !*heada)
		return ;
	
	min_node = find_min(heada);
	
	if (min_node->above_median)
	{
		while ((*heada)->value != min_node->value)
			ra(heada, true);
	}
	else
	{
		while ((*heada)->value != min_node->value)
			rra(heada, true);
	}
}