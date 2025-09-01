/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:16:25 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 11:16:42 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	rra(t_node **head, bool print)
{
	t_node	*last;
	t_node	*second_last;

	if (!head || !*head || !(*head)->next)
		return ;
	last = *head;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **head, bool print)
{
	t_node	*last;
	t_node	*second_last;

	if (!head || !*head || !(*head)->next)
		return ;
	last = *head;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **head1, t_node **head2, bool print)
{
	if (head1 && *head1 && (*head1)->next)
		rra(head1, false);
	if (head2 && *head2 && (*head2)->next)
		rrb(head2, false);
	if (print)
		write(1, "rrr\n", 4);
}
