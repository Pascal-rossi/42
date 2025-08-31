#include "push_swap_utils.h"

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

void	push_smin_to_stackb(t_node **heada, t_node **headb, t_node *second_min)
{
	if (second_min->index == 0)
		pb(heada, headb, true);
	else if (second_min->index == 1)
	{
		sa(heada, true);
		pb(heada, headb, true);
	}
	else if (second_min->index == 2)
	{
		ra(heada, true);
		ra(heada, true);
		pb(heada, headb, true);
	}
	else if (second_min->index == 3)
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
	push_min_to_stackb(heada, headb, min);
	add_index(heada);
	second_min = find_second_min(heada);
	push_smin_to_stackb(heada, headb, second_min);
	sort_3(heada);
	pa(heada, headb, true);
	pa(heada, headb, true);
}