/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:40:34 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 14:56:51 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	is_seperator(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

void	freeall(char **tab, int size)
{
	while (size >= 0)
	{
		free (tab[size]);
		size--;
	}
	free (tab);
}

int	count_word(char *str)
{
	int	in_word;
	int	count;
	int	i;

	in_word = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_seperator(str[i]) && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (is_seperator(str[i]))
			in_word = 0;
		i++;
	}
	return (count);
}

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
			i++;
		}
		else
			str++;
	}
	tab[i] = NULL;
	return (tab);
}
