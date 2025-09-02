/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:21:02 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/02 08:50:39 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_stack(t_node **head)
{
	t_node	*current;
	t_node	*next;

	if (!head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

void	free_all(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
}

void	clean_exit(t_node **a, t_node **b, int *arr, int exit_code)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	if (arr)
		free(arr);
	if (exit_code == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(exit_code);
}

void	clean_error(void *res1, void *res2, void *res3, char **tab)
{
	if (res1)
		free(res1);
	if (res2)
		free(res2);
	if (res3)
		free(res3);
	if (tab)
		free_split(tab);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
