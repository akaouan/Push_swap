/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:39:01 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/06 16:42:13 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/push_swap.h"

int	is_elem1(t_list *stack, int num)
{
	t_list	*head;

	head = stack;
	while (head != NULL)
	{
		if (head->index == num)
			return (1);
		head = head->next;
	}
	return (0);
}

int	min_num(t_list *stack_a)
{
	int		i;
	int		min;
	t_list	*head;

	i = 0;
	head = stack_a;
	min = head->index;
	while (head)
	{
		if (head->index < min)
			min = head->index;
		i++;
		head = head->next;
	}
	return (min);
}

int	up_down(t_list *stack_a, int num)
{
	int		i;
	t_list	*head;

	head = stack_a;
	i = 0;
	while (i < ft_lstsize(stack_a) / 2)
	{
		if (head->index == num)
			return (1);
		head = head->next;
		i++;
	}
	return (0);
}

void	sort_tr(t_list **stack_a)
{
	int	first;
	int	second;
	int	last;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	last = (*stack_a)->next->next->index;
	if (first > second && second > last && last < first)
	{
		swap(stack_a, 'a');
		rr(stack_a, 'a');
	}
	else if (first > second && second < last && last < first)
		r(stack_a, 'a');
	else if (first < second && second > last && last > first)
	{
		rr(stack_a, 'a');
		swap(stack_a, 'a');
	}
	else if (first < second && second > last && last < first)
		rr(stack_a, 'a');
	else if (first > second && second < last && last > second)
		swap(stack_a, 'a');
}

void	push_min(t_list **stack_a, t_list **stack_b, int size)
{
	int	num;

	num = min_num(*stack_a);
	while (size)
	{
		while (1)
		{
			if ((*stack_a)->index == num)
			{
				push_b(stack_a, stack_b);
				num = min_num(*stack_a);
				size--;
				break ;
			}
			if (up_down(*stack_a, num))
				r(stack_a, 'a');
			else
				rr(stack_a, 'a');
		}
	}
}
