/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:00:10 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/06 17:08:40 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdlib.h>
# include<unistd.h>

typedef struct s_list
{
	int				index;
	int				p;
	struct s_list	*next;
}t_list;

typedef struct f_list
{
	int	min;
	int	max;
	int	mid;
}t_range;

typedef struct f_element{
	int		i;
	int		j;
	int		size;
	int		stack_size;
	int		*tab;
	t_list	*stack_a;
	t_list	*stack_b;
}t_elemnts;

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int integer);
long	ft_atoi(char *str);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	swap_index(int *a, int *b);
void	sort_tab(int *tab, int size);
void	r(t_list **stack, char c);
void	rr(t_list **stack, char c);
void	swap(t_list **stack, char c);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
int		index_t(int num, int *tab);
int		is_valid(int ac, char **av);
void	sort_five(t_list **stack_a, t_list **stack_b, int size);
void	sort_tr(t_list **stack_a);
int		is_sorted(int ac, char **av);
void	sort_stack(t_list **stack_a, t_list **stack_b);
int		is_elem(t_list *stack, t_range *range);
void	init_range(t_list *stack_a, t_range *range);
void	new_range(t_list *stack_a, t_range *range);
void	put_index(t_list *stack, int *tab);
int		up_or_down(t_list *stack, t_range *range);
void	push_elms(t_list **stack_a,
			t_list **stack_b, t_range *range, int up_down);
int		is_elem1(t_list *stack, int num);
void	push_min(t_list **stack_a, t_list **stack_b, int size);
int		up_down(t_list *stack_a, int num);
int		check_argements(char **av);
int		check_duplicate(int ac, char **av);

#endif
