/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:49:25 by palkhour          #+#    #+#             */
/*   Updated: 2025/09/02 11:24:06 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	int				cost_a;
	int				cost_b;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

char	**ft_split(char *str);
void	freeall(char **tab, int size);
int		*parse_input(int args, char **argv, int *size);
int		*fill_arr(char **tab, int count);
void	error(void);
int		check_duplicate(int *arr, int size);
int		ft_atoi(char *str);
long	ft_atol(const char *str);
void	fill_list(int *arr, int size, t_node **head);
int		ft_strlen(char *str);
int		is_seperator(char c);
int		is_int_range(const char *str);

bool	is_sorted(t_node **head);
int		stack_size(t_node **head);
void	choose_sort(t_node **heada, t_node **headb);

void	sa(t_node **head, bool print);
void	sb(t_node **head, bool print);
void	ss(t_node **head1, t_node **head2, bool print);
void	pa(t_node **head1, t_node **head2, bool print);
void	pb(t_node **head1, t_node **head2, bool print);
void	ra(t_node **head, bool print);
void	rb(t_node **head, bool print);
void	rr(t_node **head1, t_node **head2, bool print);
void	rra(t_node **head, bool print);
void	rrb(t_node **head, bool print);
void	rrr(t_node **head1, t_node **head2, bool print);
void	ra_ra_pb(t_node **heada, t_node **headb);
void	sa_pb(t_node **heada, t_node **headb);

void	sort_3(t_node **head);
void	sort_4(t_node **heada, t_node **headb);
void	push_min_to_stackb(t_node **heada, t_node **headb, t_node *min);
void	push_smin_to_stackb(t_node **heada, t_node **headb, t_node *second_min);
void	sort_5(t_node **heada, t_node **headb);

void	set_positions(t_node **head);
void	find_target_nodes(t_node **heada, t_node **headb);
void	init_nodes(t_node **heada, t_node **headb);
void	big_sort(t_node **heada, t_node **headb);

t_node	*find_cheapest(t_node **headb);
void	set_cheapest(t_node **headb);
void	calculate_costs(t_node **heada, t_node **headb);

void	free_split(char **tab);
void	clean_exit(t_node **a, t_node **b, int *arr, int exit_code);
void	free_stack(t_node **head);
void	free_all(t_node **a, t_node **b);
void	clean_error(void *res1, void *res2, void *res3, char **tab);

void	add_index(t_node **head);
t_node	*find_second_min(t_node **head);
t_node	*find_max(t_node **head);
t_node	*find_min(t_node **head);

void	final_rotation(t_node **heada);
void	rotate_b_to_top(t_node **headb, t_node *cheapest);
void	rotate_a_to_target(t_node **heada, t_node *target);
void	rotate_both(t_node **heada, t_node **headb, t_node *cheapest);
void	move_nodes(t_node **heada, t_node **headb, t_node *cheapest);

int		is_number(const char *str);
void	push_smaller_elements(t_node **heada, t_node **headb, int size);
#endif