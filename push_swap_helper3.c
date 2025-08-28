/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:37:23 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/28 17:40:30 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	push_smin_to_stackb(t_node **heada, t_node **headb, t_node *second_min)
{
	if (second_min->index == 0)
		pb(heada, headb, true);
	else if (second_min->index == 1)
	{
		sa(heada, true);
		pb(heada, headb, true);
	}
	else if (second_min->index == 2)
	{
		ra(heada, true);
		ra(heada, true);
		pb(heada, headb, true);
	}
	else if (second_min->index == 3)
	{
		rra(heada, true);
		pb(heada, headb, true);
	}
}

void	find_target_node_helper(t_node **heada, t_node **headb)
{
	t_node	*head_a;

	head_a = *heada;
	while (head_a)
	{
		if (head_a->target_node == NULL)
			head_a->target_node = find_max(headb);
		head_a = head_a->next;
	}
}

void	find_target_node(t_node **heada, t_node **headb)
{
	t_node	*head_a;
	t_node	*head_b;
	int		difference;

	if (!heada || !headb || !*heada || !*headb)
		return ;
	head_a = *heada;
	while (head_a)
	{
		difference = INT_MAX;
		head_b = *headb;
		while (head_b)
		{
			if (head_a->value - head_b->value > 0
				&& head_a->value - head_b->value < difference)
			{
				difference = head_a->value - head_b->value;
				head_a->target_node = head_b;
			}
			head_b = head_b->next;
		}
		head_a = head_a->next;
	}
	find_target_node_helper(heada, headb);
}
