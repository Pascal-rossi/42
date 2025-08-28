/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:12:10 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/28 15:17:14 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

void	rrb(t_node **head1, bool print)
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
	slast->next = *head1;
	(*head1)->prev = slast;
	flast->next = NULL;
	*head1 = slast;
	slast->prev = NULL;
	if (print)
	{
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_node **head1, t_node **head2, bool print)
{
	rra(head1, false);
	rrb(head2, false);
	if (print)
	{
		write(1, "rrr\n", 4);
	}
}
