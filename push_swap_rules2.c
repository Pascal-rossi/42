/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:15:58 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 13:14:07 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	ra(t_node **head, bool print)
{
	t_node	*first;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_node **head, bool print)
{
	t_node	*first;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_node **head1, t_node **head2, bool print)
{
	if (head1 && *head1 && (*head1)->next)
		ra(head1, false);
	if (head2 && *head2 && (*head2)->next)
		rb(head2, false);
	if (print)
		write(1, "rr\n", 3);
}
