/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:25:05 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/02 08:53:52 by palkhour         ###   ########.fr       */
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
		if (!is_number(tab[i]) || !is_int_range(tab[i]))
		{
			free(arr);
			free_split(tab);
			error();
		}
		arr[i] = ft_atoi(tab[i]);
		i++;
	}
	free_split(tab);
	return (arr);
}

int	is_int_range(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && num > (long long)INT_MAX + 1))
			return (0);
		str++;
	}
	return (1);
}

int	*parse_input_helper(int args, char **argv, int *size)
{
	int	*arr;
	int	i;

	i = -1;
	arr = malloc(sizeof(int) * (args - 1));
	if (!arr)
		error();
	while (++i < args - 1)
	{
		if (!is_number(argv[i + 1]) || !is_int_range(argv[i + 1]))
			clean_error(arr, NULL, NULL, NULL);
		arr[i] = ft_atoi(argv[i + 1]);
	}
	if (!check_duplicate(arr, args - 1))
		clean_error(arr, NULL, NULL, NULL);
	*size = args - 1;
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
			clean_exit(NULL, NULL, NULL, 1);
		while (tab[count])
			count++;
		arr = fill_arr(tab, count);
		*size = count;
	}
	else
		arr = parse_input_helper(args, argv, size);
	if (!check_duplicate(arr, *size))
		clean_error(arr, NULL, NULL, NULL);
	return (arr);
}
