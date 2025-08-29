/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:10:44 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/29 11:24:21 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	pb(t_node **head1, t_node **head2, bool print)
{
	t_node	*tmpb;

	if (!head1 || !(*head1))
		return ;
	tmpb = *head1;
	*head1 = tmpb->next;
	if (*head1)
		(*head1)->prev = NULL;
	tmpb->next = *head2;
	tmpb->prev = NULL;
	if (*head2)
		(*head2)->prev = tmpb;
	*head2 = tmpb;
	if (print)
	{
		write(1, "pb\n", 3);
	}
}

void	ra(t_node **head1, bool print)
{
	t_node	*first;
	t_node	*last;

	if (!head1 || !*head1 || !(*head1)->next)
		return ;
	first = *head1;
	last = *head1;
	while (last->next)
		last = last->next;
	*head1 = first->next;
	(*head1)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	if (print)
	{
		write(1, "ra\n", 3);
	}
}

void	rb(t_node **head2, bool print)
{
	t_node	*first;
	t_node	*last;

	if (!head2 || !*head2 || !(*head2)->next)
		return ;
	first = *head2;
	last = *head2;
	while (last->next)
		last = last->next;
	*head2 = first->next;
	(*head2)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	if (print)
	{
		write(1, "rb\n", 3);
	}
}

void	rr(t_node **head1, t_node **head2)
{
	rb(head2, false);
	ra(head1, false);
}
