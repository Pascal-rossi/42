#include "push_swap_utils.h"

void	bubble_sort(int *a, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
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

void	assign_indexes(t_node **head, int *sorted_arr, int size)
{
	int		i;
	t_node	*h;

	if (!head || !*head)
		return ;
	i = 0;
	while (i < size)
	{
		h = *head;
		while (h)
		{
			if (h->value == sorted_arr[i])
			{
				h->index = i;
				break ;
			}
			h = h->next;
		}
		i++;
	}
}