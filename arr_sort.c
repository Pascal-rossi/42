/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:22:38 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/02 11:23:41 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int	find_median(t_node *head)
{
	int		*arr;
	int		size;
	int		i;
	int		median;
	t_node	*current;

	if (!head)
		return (0);
	size = stack_size(&head);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	current = head;
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	bubble_sort(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}

void	push_smaller_elements(t_node **heada, t_node **headb, int size)
{
	int		median;
	int		pushed;
	int		i;

	median = find_median(*heada);
	pushed = 0;
	i = 0;
	while (i < size && pushed < size / 2)
	{
		if ((*heada)->value < median)
		{
			pb(heada, headb, true);
			pushed++;
		}
		else
			ra(heada, true);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(heada, headb, true);
		pushed++;
	}
}
