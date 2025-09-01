/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:29:15 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 14:44:22 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	set_positions(t_node **head)
{
	int		pos;
	t_node	*current;
	int		size_stack;

	if (!head || !*head)
		return ;
	pos = 0;
	current = *head;
	size_stack = stack_size(head);
	while (current)
	{
		current->index = pos;
		current->above_median = (pos <= size_stack / 2);
		current = current->next;
		pos++;
	}
}

void	h(t_node *current_a, t_node **target, long *bmatch, t_node *current_b)
{
	while (current_a)
	{
		if (current_a->value > current_b->value
			&& current_a->value < *bmatch)
		{
			*bmatch = current_a->value;
			*target = current_a;
		}
		current_a = current_a->next;
	}
}

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
		h(current_a, &target, &best_match, current_b);
		if (best_match == LONG_MAX)
			current_b->target_node = find_min(heada);
		else
			current_b->target_node = target;
		current_b = current_b->next;
	}
}

void	init_nodes(t_node **heada, t_node **headb)
{
	set_positions(heada);
	set_positions(headb);
	find_target_nodes(heada, headb);
	calculate_costs(heada, headb);
	set_cheapest(headb);
}

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
