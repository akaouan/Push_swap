/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:42:38 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/06 16:45:03 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/push_swap.h"

void	swap(t_list **stack, char c)
{
	t_list	*current;
	t_list	*third;
	t_list	*head;

	head = *stack;
	current = head->next;
	third = current->next;
	current->next = head;
	head->next = third;
	*stack = current;
	if (c == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	rr(t_list **stack, char c)
{
	t_list	*second_prev_node;
	t_list	*last_node;

	if (*stack == NULL || ft_lstsize(*stack) < 2)
		return ;
	second_prev_node = *stack;
	last_node = ft_lstlast(*stack);
	while ((second_prev_node)->next->next != NULL)
		(second_prev_node) = (second_prev_node)->next;
	(second_prev_node)->next = NULL;
	ft_lstadd_front(stack, last_node);
	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	r(t_list **stack, char c)
{
	t_list	*first;
	t_list	*last_node;
	t_list	*second_node;

	if (*stack == NULL || ft_lstsize(*stack) < 2)
		return ;
	second_node = (*stack)->next;
	first = *stack;
	last_node = ft_lstlast(*stack);
	*stack = second_node;
	last_node->next = first;
	first->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	head = *stack_a;
	*stack_a = (*stack_a)->next;
	head->next = NULL;
	ft_lstadd_front(stack_b, head);
	write(1, "pb\n", 3);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	head = *stack_b;
	*stack_b = (*stack_b)->next;
	head->next = NULL;
	ft_lstadd_front(stack_a, head);
	write(1, "pa\n", 3);
}
