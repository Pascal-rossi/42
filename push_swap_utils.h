/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:10:54 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/29 11:18:01 by palkhour         ###   ########.fr       */
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

// Stack operations
void	pa(t_node **head1, t_node **head2, bool print);
void	pb(t_node **head1, t_node **head2, bool print);
void	sa(t_node **head, bool print);
void	sb(t_node **head, bool print);
void	ss(t_node **head1, t_node **head2, bool print);
void	ra(t_node **head, bool print);
void	rb(t_node **head, bool print);
void	rr(t_node **head1, t_node **head2);
void	rra(t_node **head, bool print);
void	rrb(t_node **head, bool print);
void	rrr(t_node **head1, t_node **head2, bool print);

// Sorting algorithms
void	sort_3(t_node **head);
void	sort_4(t_node **heada, t_node **headb);
void	sort_5(t_node **heada, t_node **headb);
void	big_sort(t_node **heada, t_node **headb);
void	choose_sort(t_node **heada, t_node **headb);

// Node manipulation
void	add_index(t_node **head);
void	assign_indexes(t_node **head, int *sorted_arr, int *size);
void	assign_cost(void);
void	init_nodes(t_node **heada, t_node **headb);
void	set_positions(t_node **head);
void	find_target_nodes(t_node **heada, t_node **headb);
void	calculate_costs(t_node **heada, t_node **headb);
void	set_cheapest(t_node **headb);

// Node finding utilities
t_node	*find_min(t_node **head);
t_node	*find_max(t_node **head);
t_node	*find_second_min(t_node **head);
t_node	*find_cheapest(t_node **headb);

// Movement functions
void	move_nodes(t_node **heada, t_node **headb, t_node *cheapest);
void	rotate_both(t_node **heada, t_node **headb, t_node *cheapest);
void	rotate_a_to_target(t_node **heada, t_node *target);
void	rotate_b_to_top(t_node **headb, t_node *cheapest);
void	final_rotation(t_node **heada);

// Push helpers
void	push_min_to_stackb(t_node **heada, t_node **headb, t_node *min);
void	push_min_to_stackb_sort4(t_node **heada, t_node **headb, t_node *min);
void	push_smin_to_stackb(t_node **heada, t_node **headb, t_node *second_min);

// Input parsing & validation
int		*parse_input(int args, char **argv, int *size);
int		*parse_input_helper(int args, char **argv, int *size);
void	parse_input_checker(char **argv);
int		*fill_arr(char **tab, int count);
int		ft_atoi(char *str);
void	ft_atoi_helper(char *str, int index, long long *res, int sign);
int		check_duplicate(int *arr, int size);
bool	check_sorted(t_node **head);
bool	is_sorted(t_node **head);

// String utilities
char	**ft_split(char *str);
char	*dup_word(char *c, int len);
int		count_word(char *c);
int		ft_strlen(char *str);
int		is_seperator(char c);

// Stack utilities
void	fill_list(int *arr, int size, t_node **head);
int		stack_size(t_node **head);
void	start_the_turk(t_node **head1, t_node **headb);
void	copy_unsorted_array(int *source, int *size, int *dest);
void	bubble_sort(int *a, int *size);

// Memory management
void	free_stack(t_node **head);
void	free_all(t_node **a, t_node **b);
void	free_split(char **tab);
void	freeall(char **tab, int last);

// Error handling
void	error(void);

// Debug utilities
void	print_stack(t_node *head, char stack_name);
void	print_array(int *arr, int size);

#endif