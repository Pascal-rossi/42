/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:36:12 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 13:04:38 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

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
		current->push_cost = current->index;
		if (!current->above_median)
			current->push_cost = sb - current->index;
		if (current->target_node->above_median)
			current->push_cost += current->target_node->index;
		else
			current->push_cost += sa - current->index;
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
