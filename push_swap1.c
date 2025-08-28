/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:42:18 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/28 17:43:12 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

char	*dup_word(char *c, int len)
{
	int		i;
	char	*arr;

	i = 0;
	arr = malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = c[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

void	freeall(char **tab, int last)
{
	while (last >= 0)
	{
		free(tab[last]);
		last--;
	}
	free(tab);
}

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (!is_seperator(str[len]) && str[len])
		len++;
	return (len);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (count_word(str) + 1));
	if (!tab)
		return (NULL);
	while (*str)
	{
		if (!is_seperator(*str))
		{
			tab[i] = dup_word(str, ft_strlen(str));
			if (!tab[i])
				return (freeall(tab, i - 1), NULL);
			str += ft_strlen(str);
		}
		else
			str++;
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_atoi_helper(char *str, int index, long long *res, int sign)
{
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
		{
			*res = *res * 10 + (str[index] - '0');
			if ((sign == 1 && *res > INT_MAX)
				|| (sign == -1 && *res > (long long)INT_MAX + 1))
			{
				error();
			}
		}
		else
			error();
		index++;
	}
	*res = *res * sign;
}
