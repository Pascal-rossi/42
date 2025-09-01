/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:37:23 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 10:48:12 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	fill_list_helper(t_node *new_node, t_node **head)
{
	new_node->index = -1;
	new_node->push_cost = 0;
	new_node->above_median = false;
	new_node->cheapest = false;
	new_node->target_node = NULL;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;
}

void	fill_list(int *arr, int size, t_node **head)
{
	int		i;
	t_node	*new_node;

	i = size - 1;
	*head = NULL;
	while (i >= 0)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
		{
			free_stack(head);
			free(arr);
			error();
		}
		new_node->value = arr[i];
		fill_list_helper(new_node, head);
		*head = new_node;
		i--;
	}
}
