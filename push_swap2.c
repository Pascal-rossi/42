/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:43:41 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/29 11:22:16 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	ft_atoi_helper(str, i, &res, sign);
	return ((int)res);
}
// void	print_array(int *arr, int size)
// {
// 	int	i;

// 	for (i = 0; i < size; i++)
// 		printf("%d", arr[i]);
// 	printf("\n");
// }

void	fill_list(int *arr, int size, t_node **head)
{
	int		i;
	t_node	*new_node;

	i = size - 1;
	*head = NULL;
	while (i >= 0)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			error();
		new_node->index = -1;
		new_node->push_cost = 0;
		new_node->above_median = false;
		new_node->cheapest = false;
		new_node->target_node = NULL;
		new_node->value = arr[i];
		new_node->next = *head;
		new_node->prev = NULL;
		if (*head)
			(*head)->prev = new_node;
		*head = new_node;
		i--;
	}
}

void	start_the_turk(t_node **head1, t_node **head2)
{
	pb(head1, head2, true);
	if ((*head2)->value > (*head2)->next->value)
		sb(head2, true);
}

int	stack_size(t_node **head)
{
	int		count;
	t_node	*h;

	h = *head;
	count = 0;
	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}

void	choose_sort(t_node **heada, t_node **headb)
{
	int	len;

	if (!heada || !headb)
		return ;
	len = stack_size(heada);
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if ((*heada)->value > (*heada)->next->value)
			sa(heada, true);
		return ;
	}
	else if (len == 3)
		sort_3(heada);
	else if (len == 4)
		sort_4(heada, headb);
	else if (len == 5)
		sort_5(heada, headb);
	else
		big_sort(heada, headb);
}
