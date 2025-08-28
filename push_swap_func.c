/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:44:55 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/28 17:50:02 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_utils.h>

void	copy_unsorted_array(int *source, int *size, int *dest)
{
	int	*a;
	int	i;

	i = 0;
	while (i < *size)
	{
		dest[i] = source[i];
		i++;
	}
}

void	bubble_sort(int *a, int *size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < *size)
	{
		j = 0;
		while (j < *size - i - 1)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	assign_indexes(t_node **head, int *sorted_arr, int *size)
{
	int		i;
	t_node	*h;

	if (!head || !*head)
		return ;
	i = 0;
	while (i < *size)
	{
		h = *head;
		while (h)
		{
			if (h->value == sorted_arr[i])
			{
				h->index = i;
				break ;
			}
			h = h->next;
		}
		i++;
	}
	free(sorted_arr);
}
void	assign_cost()
{
	
}
