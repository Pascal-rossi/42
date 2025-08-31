#include "push_swap_utils.h"

int	stack_size(t_node **head)
{
	int		count;
	t_node	*current;

	if (!head || !*head)
		return (0);
	count = 0;
	current = *head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	stack_size_node(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	copy_unsorted_array(int *source, int size, int *dest)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = source[i];
		i++;
	}
}
