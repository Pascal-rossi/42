/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:54:32 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 13:54:43 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

t_node	*find_min(t_node **head)
{
	t_node	*current;
	t_node	*min_node;

	if (!head || !*head)
		return (NULL);
	current = *head;
	min_node = current;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_node	*find_max(t_node **head)
{
	t_node	*current;
	t_node	*max_node;

	if (!head || !*head)
		return (NULL);
	current = *head;
	max_node = current;
	while (current)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_node	*find_second_min(t_node **head)
{
	t_node	*current;
	t_node	*min_node;
	t_node	*second_min;
	int		second_min_value;

	if (!head || !*head || !(*head)->next)
		return (NULL);
	min_node = find_min(head);
	current = *head;
	second_min = NULL;
	second_min_value = INT_MAX;
	while (current)
	{
		if (current != min_node && current->value < second_min_value)
		{
			second_min_value = current->value;
			second_min = current;
		}
		current = current->next;
	}
	return (second_min);
}

void	add_index(t_node **head)
{
	int		index;
	t_node	*current;

	if (!head || !*head)
		return ;
	index = 0;
	current = *head;
	while (current)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}
