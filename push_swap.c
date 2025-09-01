/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puh_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:22:24 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/01 10:34:53 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	main(int args, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		*arr;
	int		size;

	a = NULL;
	b = NULL;
	arr = NULL;
	if (args < 2)
		return (0);
	arr = parse_input(args, argv, &size);
	fill_list(arr, size, &a);
	if (!is_sorted(&a))
		choose_sort(&a, &b);
	clean_exit(&a, &b, arr, 0);
	return (0);
}
