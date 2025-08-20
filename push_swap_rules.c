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

void sa(snode **head)
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
}
void sb(snode **head)
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
}
void ss(snode **head1, snode **head2)
{
	if(!head1 || !head2)
		return ;
	sa(head1);
	sb(head2);
}void rra(snode **head1)
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
	flast->next = NULL;
	slast->prev = NULL;
	slast->next = *head1;
	(*head1)->prev = slast;
	*head1 = slast;
}
void pa(snode **head1, snode **head2)
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
}
void pb(snode **head1, snode **head2)
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
}
void ra(snode **head1)
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
}
void rb(snode **head2)
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
}
void	rr(snode **head1, snode **head2)
{
	rb(head2);
	ra(head1);
}
void rra(snode **head1)
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
}
void rrb(snode **head1)
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
}
void rrr(snode **head1,snode **head2)
{
	rra(head1);
	rrb(head2);
}