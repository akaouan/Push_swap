/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:03:40 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/07 18:03:45 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_list **stack)
{
	t_list	*current;
	t_list	*third;
	t_list	*head;

	if (!(*stack) || ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	current = head->next;
	third = current->next;
	current->next = head;
	head->next = third;
	*stack = current;
}

void	rr(t_list **stack)
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
}

void	r(t_list **stack)
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
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	if (!(*stack_a))
		return ;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	head->next = NULL;
	ft_lstadd_front(stack_b, head);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	if (!(*stack_b))
		return ;
	head = *stack_b;
	*stack_b = (*stack_b)->next;
	head->next = NULL;
	ft_lstadd_front(stack_a, head);
}
