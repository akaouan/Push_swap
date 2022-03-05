/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:06:00 by akaouan           #+#    #+#             */
/*   Updated: 2021/11/11 11:06:59 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Headers/push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (i);
	else
	{
		while (lst != NULL)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}
