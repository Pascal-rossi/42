#include "push_swap_utils.h"

void	sa(t_node **head, bool print)
{
	t_node	*first;
	t_node	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	second->prev = first->prev;
	first->prev = second;
	*head = second;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_node **head, bool print)
{
	t_node	*first;
	t_node	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	second->prev = first->prev;
	first->prev = second;
	*head = second;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_node **head1, t_node **head2, bool print)
{
	if (head1 && *head1 && (*head1)->next)
		sa(head1, false);
	if (head2 && *head2 && (*head2)->next)
		sb(head2, false);
	if (print)
		write(1, "ss\n", 3);
}

void	pa(t_node **head1, t_node **head2, bool print)
{
	t_node	*tmp;

	if (!head2 || !*head2)
		return ;
	tmp = *head2;
	*head2 = tmp->next;
	if (*head2)
		(*head2)->prev = NULL;
	tmp->next = *head1;
	tmp->prev = NULL;
	if (*head1)
		(*head1)->prev = tmp;
	*head1 = tmp;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_node **head1, t_node **head2, bool print)
{
	t_node	*tmp;

	if (!head1 || !*head1)
		return ;
	tmp = *head1;
	*head1 = tmp->next;
	if (*head1)
		(*head1)->prev = NULL;
	tmp->next = *head2;
	tmp->prev = NULL;
	if (*head2)
		(*head2)->prev = tmp;
	*head2 = tmp;
	if (print)
		write(1, "pb\n", 3);
}