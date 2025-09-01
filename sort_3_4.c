/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:20:19 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 11:26:50 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	sort_3(t_node **head)
{
	int	first;
	int	second;
	int	third;

	if (!head || !*head || stack_size(head) < 3)
		return ;
	first = (*head)->value;
	second = (*head)->next->value;
	third = (*head)->next->next->value;
	if (first > second && second < third && first < third)
		sa(head, true);
	else if (first > second && second > third)
	{
		sa(head, true);
		rra(head, true);
	}
	else if (first > second && second < third && first > third)
		ra(head, true);
	else if (first < second && second > third && first < third)
	{
		sa(head, true);
		ra(head, true);
	}
	else if (first < second && second > third && first > third)
		rra(head, true);
}

void	push_min_to_stackb_sort4(t_node **heada, t_node **headb, t_node *min)
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
		pb(heada, headb, true);
	}
}

void	sort_4(t_node **heada, t_node **headb)
{
	t_node	*min;

	if (!heada || !*heada)
		return ;
	add_index(heada);
	min = find_min(heada);
	push_min_to_stackb_sort4(heada, headb, min);
	sort_3(heada);
	pa(heada, headb, true);
}
