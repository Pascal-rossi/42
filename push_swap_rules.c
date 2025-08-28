/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:14:06 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/28 15:19:12 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h" 

void	sa(t_node **head, bool print)
{
	t_node	*tmpa;
	t_node	*tmpb;

	if (!head || !(*head)->next)
		return ;
	tmpa = *head;
	tmpb = (*head)->next;
	tmpa->next = tmpb->next;
	tmpb->next = tmpa;
	if (tmpa->next)
		tmpa->next->prev = tmpa;
	tmpb->prev = tmpa->prev;
	tmpa->prev = tmpb;
	*head = tmpb;
	if (print)
	{
		write(1, "sa\n", 3);
	}
}

void	sb(t_node **head, bool print)
{
	t_node	*tmpa;
	t_node	*tmpb;

	if (!head || !(*head)->next)
		return ;
	tmpa = *head;
	tmpb = (*head)->next;
	tmpa->next = tmpb->next;
	tmpb->next = tmpa;
	if (tmpa->next)
		tmpa->next->prev = tmpa;
	tmpb->prev = tmpa->prev;
	tmpa->prev = tmpb;
	*head = tmpb;
	if (print)
	{
		write(1, "sb\n", 3);
	}
}

void	ss(t_node **head1, t_node **head2, bool print)
{
	if (!head1 || !head2)
		return ;
	sa(head1, false);
	sb(head2, false);
	if (print)
	{
		write(1, "ss\n", 3);
	}
}

void	rra(t_node **head1, bool print)
{
	t_node	*slast;
	t_node	*flast;

	if (!head1 || !*head1 || !(*head1)->next)
		return ;
	flast = *head1;
	while (flast->next->next)
	{
		flast = flast->next;
	}
	slast = flast->next;
	flast->next = NULL;
	slast->prev = NULL;
	slast->next = *head1;
	(*head1)->prev = slast;
	*head1 = slast;
	if (print)
	{
		write(1, "rra\n", 4);
	}
}

void	pa(t_node **head1, t_node **head2, bool print)
{
	t_node	*tmpa;

	if (!head2 || !(*head2))
		return ;
	tmpa = *head2;
	*head2 = tmpa->next;
	if (*head2)
		(*head2)->prev = NULL;
	tmpa->next = *head1;
	tmpa->prev = NULL;
	if (*head1)
		(*head1)->prev = tmpa;
	*head1 = tmpa;
	if (print)
	{
		write(1, "pa\n", 3);
	}
}
