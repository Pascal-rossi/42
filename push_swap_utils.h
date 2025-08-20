/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palkhour <palkhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:10:54 by palkhour          #+#    #+#             */
/*   Updated: 2025/08/19 10:31:11 by palkhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
typedef struct s_node {
    int             value;
    int             index;
    int             push_cost;
    bool            above_median;
    bool            cheapest;
    struct s_node   *target_node;
    struct s_node  *prev;
    struct s_node  *next;
}snode;

#endif