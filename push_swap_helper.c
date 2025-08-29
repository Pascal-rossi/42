/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:12:54 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/29 11:24:00 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

t_node	*find_max(t_node **headb)
{
	int		max;
	t_node	*node;
	t_node	*max_node;

	if (!headb || !*headb)
		return (NULL);
	if (!(*headb)->next)
		return (*headb);
	max = (*headb)->value;
	max_node = *headb;
	node = *headb;
	while (node)
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

t_node	*find_min(t_node **heada)
{
	int		min;
	t_node	*node;
	t_node	*min_node;

	if (!heada || !*heada)
		return (NULL);
	if (!(*heada)->next)
		return (*heada);
	min = (*heada)->value;
	min_node = *heada;
	node = *heada;
	while (node)
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

t_node	*find_second_min(t_node **head)
{
	int		second_min;
	t_node	*node;
	t_node	*min_node;
	t_node	*second_min_node;

	node = *head;
	min_node = find_min(head);
	second_min_node = NULL;
	second_min = INT_MAX;
	while (node)
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

void	add_index(t_node **head)
{
	int		index;
	t_node	*h;

	index = 0;
	h = *head;
	if (!h)
		return ;
	while (h)
	{
		h->index = index;
		h = h->next;
		index++;
	}
}

void	push_min_to_stackb(t_node **heada, t_node **headb, t_node *min)
{
	if (min->index == 0)
		pb(heada, headb, true);
	else if (min->index == 1)
	{
		sa(heada, true);
		pb(heada, headb, true);
	}
	else if (min->index == 2)
	{
		ra(heada, true);
		ra(heada, true);
		pb(heada, headb, true);
	}
	else if (min->index == 3)
	{
		rra(heada, true);
		rra(heada, true);
		pb(heada, headb, true);
	}
	else if (min->index == 4)
	{
		rra(heada, true);
		pb(heada, headb, true);
	}
}
