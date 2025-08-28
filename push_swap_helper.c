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
snode *find_second_min(snode **head)
{
	int		min;
	int		second_min;
	snode	*node;
	snode	*min_node;
	snode	*second_min_node;

	node = *head;
	min_node = find_min(head);
	min = min_node->value;
	second_min_node = NULL;
	second_min = INT_MAX;
	while(node)
	{
		if (node->value < second_min && node != min_node)
		{	
			second_min = node->value;
			second_min_node = node;
		}
		node = node->next;
	}
	return (second_min_node);
}
bool	check_sorted(snode **head)
{
	snode *node;
	node = *head;

	if(!node || !node->next)
		return (true);
	while(node->next)
	{
		if(node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}
void free_stack(snode **head)
{
	snode *new_head;
	while(*head)
	{
		new_head = (*head)->next;
		free(*head);
		*head = new_head;
	}
	*head = NULL;
}
void free_all(snode **a, snode **b)
{
	free_stack(a);
	free_stack(b);
}
void sort_3_helper(int f, int s, int t, snode **head)
{
	if(f < s && s < t)
		return ;
	else if(f > s && s < t && f < t)//2 1 3
		sa(head, true); 
	else if(f > s && s > t)// 3 2 1
	{
		sa(head, true);
		rra(head, true);	
	}
	else if(f > s && s < t && f > t)// 3 1 2
		ra(head, true);
	else if(f < s && s > t && f < t)// 1 3 2
	{
		sa(head, true);
		ra(head, true);
	}
	else if (f < s && s > t && f > t)// 2 3 1
		rra(head, true);
}
void sort_3(snode **head)
{
	int f;
	int s;
	int t;

	if (!head || !*head || !(*head)->next || !(*head)->next->next)
		return;
	f = (*head)->value;
	s = (*head)->next->value;
	t = (*head)->next->next->value;
	sort_3_helper(f,s,t,head);
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
void sort_5(snode **heada, snode **headb)
{

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
