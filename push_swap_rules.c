/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:14:06 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/19 11:55:53 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h" 

void sa(snode **head, bool print)
{
	snode	*tmpa;
	snode	*tmpb;

	if(!head || !(*head)->next)
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
void sb(snode **head, bool print)
{
	snode	*tmpa;
	snode	*tmpb;

	if(!head || !(*head)->next)
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
void ss(snode **head1, snode **head2, bool print)
{
	if(!head1 || !head2)
		return ;
	sa(head1, false);
	sb(head2, false);
	if (print)
	{
		write(1, "ss\n", 3);
	}
}
void rra(snode **head1)
{
	snode	*slast;
	snode	*flast;

	if (!head1 || !*head1 || !(*head1)->next, bool print)
		return ;
	flast = *head1;
	while(flast->next->next)
	{
		flast=flast->next;
	}
	slast=flast->next;
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
void pa(snode **head1, snode **head2, bool print)
{
	snode	*tmpa;

	if (!head2 || !(*head2))
		return ;
	tmpa = *head2;
	*head2 = tmpa->next;
	if(*head2)
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
void pb(snode **head1, snode **head2, bool print)
{
	snode	*tmpb;

	if (!head1 || !(*head1))
		return ;
	tmpb = *head1;
	*head1 = tmpb->next;
	if(*head1)
		(*head1)->prev = NULL;
	tmpb->next = *head2;
	tmpb->prev = NULL;
	if(*head2)
		(*head2)->prev = tmpb;
	*head2 = tmpb;
	if (print)
	{
		write(1, "pb\n", 3);
	}
}
void ra(snode **head1, bool print)
{
	snode	*first;
	snode	*last;

	if(!head1 || !*head1 || !(*head1)->next)
		return ;
	first = *head1;
	last = *head1;
	while(last->next)
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
void rb(snode **head2, bool print)
{
	snode	*first;
	snode	*last;

	if(!head2 || !*head2 || !(*head2)->next)
		return ;
	first = *head2;
	last = *head2;
	while(last->next)
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
void	rr(snode **head1, snode **head2)
{
	rb(head2, false);
	ra(head1, false);
}
void rra(snode **head1, bool print)
{
	snode	*slast;
	snode	*flast;

	if (!head1 || !*head1 || !(*head1)->next)
		return ;
	flast = *head1;
	while(flast->next->next)
	{
		flast=flast->next;
	}
	slast=flast->next;
	slast->next = *head1;
	(*head1)->prev = slast; 
	flast->next = NULL;
	*head1 = slast;
	slast->prev = NULL;
	if (print)
	{
		write(1, "rra\n", 4);
	}
}
void rrb(snode **head1, bool print)
{
	snode	*slast;
	snode	*flast;

	if (!head1 || !*head1 || !(*head1)->next)
		return ;
	flast = *head1;
	while(flast->next->next)
	{
		flast=flast->next;
	}
	slast=flast->next;
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
void rrr(snode **head1,snode **head2, bool print)
{
	rra(head1, false);
	rrb(head2, false);
	if (print)
	{
		write(1, "rrr\n", 4);
	}
}