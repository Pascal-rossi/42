/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:21:25 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/02 10:41:13 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	sa_pb(t_node **heada, t_node **headb)
{
	sa(heada, true);
	if (is_sorted(heada))
		return ;
	pb(heada, headb, true);
}

void	ra_ra_pb(t_node **heada, t_node **headb)
{
	ra(heada, true);
	if (is_sorted(heada))
		return ;
	ra(heada, true);
	pb(heada, headb, true);
}

void	rra_rra_pb(t_node **heada, t_node **headb)
{
	rra(heada, true);
	if (is_sorted(heada))
		return ;
	rra(heada, true);
	pb(heada, headb, true);
}

void	push_min_to_stackb(t_node **heada, t_node **headb, t_node *min)
{
	if (min->index == 0)
		pb(heada, headb, true);
	else if (min->index == 1)
		sa_pb(heada, headb);
	else if (min->index == 2)
		ra_ra_pb(heada, headb);
	else if (min->index == 3)
		rra_rra_pb(heada, headb);
	else if (min->index == 4)
	{
		rra(heada, true);
		pb(heada, headb, true);
	}
}

void	sort_5(t_node **heada, t_node **headb)
{
	t_node	*min;
	t_node	*second_min;

	if (!heada || !*heada)
		return ;
	add_index(heada);
	min = find_min(heada);
	second_min = find_second_min(heada);
	push_min_to_stackb(heada, headb, min);
	if (is_sorted(heada))
	{
		pa(heada, headb, true);
		return ;
	}
	add_index(heada);
	second_min = find_min(heada);
	push_smin_to_stackb(heada, headb, second_min);
	sort_3(heada);
	pa(heada, headb, true);
	pa(heada, headb, true);
}
