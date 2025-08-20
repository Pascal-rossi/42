/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:12:54 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/20 17:01:21 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

snode *find_max(snode **headb)
{
	int		max;
	snode	*node;
	snode	*max_node;
	
	if (!headb || !*headb)
		return (NULL);
	if (!(*headb)->next)
		return (*headb);
	max = (*headb)->value;
	max_node = *headb;
	node = *headb;
	while(node)
	{
		if (node->value > max)
		{	
			max = node->value;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
	
}
snode *find_min(snode **heada)
{
	int		min;
	snode	*node;
	snode	*min_node;
	
	if (!heada || !*heada)
		return (NULL);
	if (!(*heada)->next)
		return (*heada);
	min = (*heada)->value;
	min_node = *heada;
	node = *heada;
	while(node)
	{
		if (node->value < min)
		{	
			min = node->value;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
	
}
void sort_3(snode **head)
{
	int count;
	snode *node;
	node = *head;
	while(node)
	{
		count++;
		node = node ->next;
	}
	node = NULL;
	if(count==3)
	{
		node = find_min(head);
	
		if(node->value == (*head)->value)
		{
			if(node->next->value > node->next->next->value)
			{
				count = node->next->value;
				node->next->value = node->next->next->value;
				node->next->next->value = count;
			}	
		}
	}
}
void	find_target_node_helper(snode **heada, snode **headb)
{
	snode *head_a;

	head_a = *heada;
	while (head_a)
	{
		if(head_a->target_node == NULL)
			head_a->target_node = find_max(headb);
		head_a = head_a->next;
	}
}

void	find_target_node(snode **heada, snode **headb)
{
	snode *head_a;
	snode *head_b;
	int difference;
	
	if(!heada || !headb || !*heada || !*headb)
		return ;
	head_a = *heada;
	while(head_a)
	{
		difference = INT_MAX;
		head_b = *headb;
		while(head_b)
		{
			if(head_a->value - head_b->value > 0 && head_a->value - head_b->value < difference)
			{
					difference = head_a->value - head_b->value;
					head_a->target_node = head_b;
			}
			head_b = head_b->next;
		}
		head_a = head_a->next;
	}
	find_target_node_helper(heada, headb);
}
