/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:02:30 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 15:33:48 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (!is_seperator(str[len]) && str[len])
		len++;
	return (len);
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

void	ft_atoi_helper(char *str, int index, long long *res, int sign)
{
	while (str[index] >= '0' && str[index] <= '9')
	{
		*res = *res * 10 + (str[index] - '0');
		if ((sign == 1 && *res > INT_MAX)
			|| (sign == -1 && *res > (long long)INT_MAX + 1))
		{
			error();
		}
		index++;
	}
	if (str[index] != '\0' && str[index] != ' ')
		error();
	*res = *res * sign;
}

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
	if (str[i] < '0' || str[i] > '9')
		error();
	ft_atoi_helper(str, i, &res, sign);
	return ((int)res);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
