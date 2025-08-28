/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:53:02 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/28 17:47:57 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	check_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] == arr[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_seperator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	count_word(char *c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (c[i])
	{
		if (!is_seperator(c[i]) && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (is_seperator(c[i]))
			in_word = 0;
		i++;
	}
	return (count);
}

int	main(int args, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		*arr;
	int		count;

	a = NULL;
	b = NULL;
	arr = parse_input(args, argv, &count);
	fill_list(arr, count, &a);
	choose_sort(&a, &b);
	print_array(arr, count);
	free(arr);
	return (0);
}
