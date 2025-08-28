/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:35:24 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/28 17:39:09 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	free_stack(t_node **head)
{
	t_node	*new_head;

	while (*head)
	{
		new_head = (*head)->next;
		free(*head);
		*head = new_head;
	}
	*head = NULL;
}

void	free_all(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
}

void	sort_3_helper(int f, int s, int t, t_node **head)
{
	if (f < s && s < t)
		return ;
	else if (f > s && s < t && f < t)
		sa(head, true);
	else if (f > s && s > t)
	{
		sa(head, true);
		rra(head, true);
	}
	else if (f > s && s < t && f > t)
		ra(head, true);
	else if (f < s && s > t && f < t)
	{
		sa(head, true);
		ra(head, true);
	}
	else if (f < s && s > t && f > t)
		rra(head, true);
}

void	sort_3(t_node **head)
{
	int	f;
	int	s;
	int	t;

	if (!head || !*head || !(*head)->next || !(*head)->next->next)
		return ;
	f = (*head)->value;
	s = (*head)->next->value;
	t = (*head)->next->next->value;
	sort_3_helper(f, s, t, head);
}
