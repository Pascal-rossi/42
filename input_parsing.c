/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:25:05 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 15:42:48 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	*fill_arr(char **tab, int count)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * count);
	if (!arr)
	{
		free_split(tab);
		error();
	}
	while (i < count)
	{
		arr[i] = ft_atoi(tab[i]);
		i++;
	}
	if (!is_number(tab[i])
		|| ft_atol(tab[i]) > INT_MAX || ft_atol(tab[i]) < INT_MIN)
	{
		free(arr);
		free_split(tab);
		clean_exit(NULL, NULL, NULL, 1);
	}
	free_split(tab);
	return (arr);
}

void	parse_checker(char **tab, int *arr, int *size)
{
	int	i;

	i = 0;
	while (i < *size)
	{
		if (!is_number(tab[i])
			|| ft_atol(tab[i]) > INT_MAX || ft_atol(tab[i]) < INT_MIN)
		{
			free(arr);
			free_split(tab);
			clean_exit(NULL, NULL, NULL, 1);
		}
		arr[i] = ft_atoi(tab[i]);
		i++;
	}
}

int	*parse_input_helper(int args, char **argv, int *size)
{
	int	count;
	int	*arr;
	int	i;

	count = args - 1;
	i = 0;
	arr = malloc(sizeof(int) * count);
	if (!arr)
		error();
	while (i < count)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (!check_duplicate(arr, count))
	{
		free(arr);
		error();
	}
	*size = count;
	return (arr);
}

int	*parse_input(int args, char **argv, int *size)
{
	char	**tab;
	int		*arr;
	int		count;

	if (args < 2)
		error();
	count = 0;
	if (args == 2)
	{
		tab = ft_split(argv[1]);
		if (!tab)
		{
			clean_exit(NULL, NULL, NULL, 1);
			error();
		}
		while (tab[count])
			count++;
		arr = fill_arr(tab, count);
		*size = count;
	}
	else
		arr = parse_input_helper(args, argv, size);
	return (arr);
}
