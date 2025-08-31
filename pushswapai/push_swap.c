#include "push_swap_utils.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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
		error();
	exit(exit_code);
}

int	check_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
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

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		*arr;
	int		size;

	a = NULL;
	b = NULL;
	arr = NULL;
	if (argc < 2)
		return (0);
	arr = parse_input(argc, argv, &size);
	fill_list(arr, size, &a);
	if (!is_sorted(&a))
		choose_sort(&a, &b);
	clean_exit(&a, &b, arr, 0);
	return (0);
}