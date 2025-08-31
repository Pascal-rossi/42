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
	{
		free(arr);
		error();
	}
	*size = count;
	return (arr);
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
	if (!check_duplicate(arr, count))
	{
		free(arr);
		free_split(tab);
		error();
	}
	free_split(tab);
	return (arr);
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
		{
			free_stack(head);
			free(arr);
			error();
		}
		new_node->value = arr[i];
		new_node->index = -1;
		new_node->push_cost = 0;
		new_node->above_median = false;
		new_node->cheapest = false;
		new_node->target_node = NULL;
		new_node->next = *head;
		new_node->prev = NULL;
		if (*head)
			(*head)->prev = new_node;
		*head = new_node;
		i--;
	}
}