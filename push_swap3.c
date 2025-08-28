/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:47:03 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/28 17:47:24 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

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
		error();
	*size = count;
	return (arr);
}

int	*fill_arr(char **tab, int count)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * count);
	while (i < count)
	{
		arr[i] = ft_atoi(tab[i]);
		i++;
	}
	if (!check_duplicate(arr, count))
		error();
	i = 0;
	while (tab[i])
		i++;
	free_all(tab, i - 1);
	return (arr);
}

void	parse_input_checker(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if ((argv[1][i] < '0' || argv[1][i] > '9') && argv[1][i] != ' '
			&& argv[1][i] != '-' && argv[1][i] != '+')
			error();
		i++;
	}
}

int	*parse_input(int args, char **argv, int *size)
{
	int		i;
	char	**tab;
	int		*arr;
	int		count;

	if (args < 2)
		error();
	i = 0;
	count = 0;
	if (args == 2)
	{
		parse_input_checker(argv);
		tab = ft_split(argv[1]);
		if (!tab)
			error();
		while (tab[count])
			count++;
		arr = fill_arr(tab, count);
		*size = count;
	}
	else
		arr = parse_input_helper(args, argv, size);
	return (arr);
}
