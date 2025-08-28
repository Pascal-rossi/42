#include "push_swap_utils.h"
void error()
{
	write(1, "Error\n",6);
	exit(EXIT_FAILURE);
}
int check_duplicate(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while(i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if(arr[j] == arr[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int is_seperator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
int count_word(char *c)
{
	int i =0, count = 0;
	int in_word = 0;

	while(c[i])
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
char *dup_word(char *c, int len)
{
	int i;
	char *arr;
	
	i = 0;
	arr = malloc(sizeof(char) * len + 1);
	if(!arr)
		return(NULL);
	while(i < len)
	{
		arr[i] = c[i];
		i++;
	}
	arr[i] = '\0';
	return(arr);
}
void freeall(char **tab, int last)
{

	while(last>=0)
	{
		free(tab[last]);
		last--;
	}
	free(tab);
}

char **ft_split(char *str)
{
	char **tab;
	int i = 0;
	int len;

	tab = (char **)malloc(sizeof(char*) * (count_word(str) + 1));
	if(!tab)
		return NULL;
	while(*str)
	{
		if(!is_seperator(*str))
		{
			len = 0;
			while(!is_seperator(str[len]) && str[len])
				len++;
			tab[i] = dup_word(str,len);
			if(!tab[i])
			{
				freeall(tab,i - 1);
				return(NULL);
			}
			str+=len;
			i++;
		}
		else
			str++;
	}
	tab[i] = NULL;
	return(tab);
}
void ft_atoi_helper(char *str, int index, long long *res, int sign)
{

	while(str[index])
	{
		if(str[index] >= '0' && str[index] <= '9')
		{
			*res = *res * 10 + (str[index] - '0');
			if ((sign == 1 && *res > INT_MAX) || (sign == -1 && *res > (long long)INT_MAX + 1))
    			error();
		}
		else
			error();
		index++;
	}
	*res = *res * sign;
}
int ft_atoi(char *str)
{
	int i;
	int sign;
	long long res;

	sign = 1;
	res = 0;
	i = 0;
	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign *= -1;
		i++;
	}
	ft_atoi_helper(str, i, &res, sign);
	return((int)res);
}
#include <stdio.h>

void print_array(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d", arr[i]);
	printf("\n");
}

void fill_list(int *arr,int size, snode **head)
{
	int i;
	snode *new_node;

	i = size - 1;
	*head = NULL;
	while(i >= 0)
	{
		new_node = malloc(sizeof(snode));
		if (!new_node)
			error();
		new_node->index = -1;
    	new_node->push_cost = 0;
    	new_node->above_median = false;
    	new_node->cheapest = false;
		new_node->target_node = NULL;
		new_node->value = arr[i];
		new_node->next = *head;
		new_node->prev = NULL;
		if (*head)
			(*head)->prev = new_node;
		*head = new_node;
		i--;
	}
}
void start_the_turk(snode **head1, snode **head2)
{
	pb(head1,head2,true);
	if((*head2)->value >(*head2)->next->value)
		sb(*head2,true);
	
}

int main(int args, char **argv)
{
	int i;
	char **tab;
	int *arr;
	int count;

	if(args < 2)
		error();
	i = 0;
	count = 0;

	if (args == 2)
	{
		while(argv[1][i])
		{
			if((argv[1][i] < '0' || argv[1][i] > '9') && argv[1][i] != ' ' && argv[1][i] != '-' && argv[1][i] != '+')
				error();
			i++;
		}

		tab = ft_split(argv[1]);
		if(!tab)
			error();
		while(tab[count])
			count++;
		i = 0;
				arr = (int *)malloc(sizeof(int) * count);
		while(i < count)
		{
			arr[i] = ft_atoi(tab[i]);
			i++;
		}
		if(!check_duplicate(arr,count))
			error();
		i = 0;
		while(tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	else
	{
		count = args - 1;
		arr = malloc(sizeof(int) * count);
		if(!arr)
			error();
		i = 0;
		while(i < count)
		{
			arr[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		if(!check_duplicate(arr, count))
			error();
	}
	print_array(arr, count);
	free(arr);
	return(0);
}
