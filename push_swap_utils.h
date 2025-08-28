/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:10:54 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/28 17:25:50 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

void	sa(t_node **head, bool print);
void	sb(t_node **head, bool print);
void	ss(t_node **head1, t_node **head2, bool print);
void	rra(t_node **head1, bool print);
void	pa(t_node **head1, t_node **head2, bool print);

#endif