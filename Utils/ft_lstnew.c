/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:01:10 by akaouan           #+#    #+#             */
/*   Updated: 2021/11/12 01:28:38 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

t_list	*ft_lstnew(int integer)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->p = integer;
	p->next = NULL;
	return (p);
}
