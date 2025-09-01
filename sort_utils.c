/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:00:51 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 11:12:46 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

bool	is_sorted(t_node **head)
{
	t_node	*current;

	if (!head || !*head)
		return (true);
	current = *head;
	while (current->next)
	{
		if (current->next->value < current->value)
			return (false);
		current = current->next;
	}
	return (true);
}

int	stack_size(t_node **head)
{
	int		count;
	t_node	*current;

	if (!head || !*head)
		return (0);
	count = 0;
	current = *head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	choose_sort(t_node **heada, t_node **headb)
{
	int	size;

	if (!heada || !*heada)
		return ;
	size = stack_size(heada);
	if (size == 2)
	{
		if ((*heada)->value > (*heada)->next->value)
			sa(heada, true);
	}
	else if (size == 3)
		sort_3(heada);
	else if (size == 4)
		sort_4(heada, headb);
	else if (size == 5)
		sort_5(heada, headb);
	else
		big_sort(heada, headb);
}
