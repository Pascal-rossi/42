/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:36:12 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/02 11:18:28 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	calculate_costs(t_node **heada, t_node **headb)
{
	t_node	*current;
	int		sa;
	int		sb;

	if (!headb || !*headb || !heada)
		return ;
	sa = stack_size(heada);
	sb = stack_size(headb);
	current = *headb;
	while (current)
	{
		current->cost_b = current->index;
		if (!current->above_median)
			current->cost_b = sb - current->index;
		current->cost_a = current->target_node->index;
		if (!current->target_node->above_median)
			current->cost_a = sa - current->target_node->index;
		current->push_cost = current->cost_a + current->cost_b;
		if ((current->above_median && current->target_node->above_median)
			|| (!current->above_median && !current->target_node->above_median))
			current->push_cost -= min(current->cost_a, current->cost_b);
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
