/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:04:41 by akaouan           #+#    #+#             */
/*   Updated: 2022/02/07 18:04:47 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include<stdlib.h>
# include<unistd.h>

typedef struct s_list
{
	int				index;
	int				p;
	struct s_list	*next;
}t_list;

typedef struct f_element{
	int		i;
	int		j;
	int		size;
	int		stack_size;
	int		*tab;
	char	*tb;
	t_list	*stack_a;
	t_list	*stack_b;
}t_elemnts;

t_list	*ft_lstnew(int integer);
void	ft_lstadd_back(t_list **lst, t_list *new);
long	ft_atoi(char *str);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	swap_index(int *a, int *b);
void	sort_tab(int *tab, int size);
void	r(t_list **stack);
void	rr(t_list **stack);
void	swap(t_list **stack);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
int		index_t(int num, int *tab);
int		is_valid(int ac, char **av);
int		is_sorted(int ac, char **av);
int		check_argements(char **av);
int		check_duplicate(int ac, char **av);
int		check_sa(char *s1, char *s2, t_list **stack_a);
int		check_sb(char *s1, char *s2, t_list **stack_b);
int		check_ss(char *s1, char *s2, t_list **stack_a, t_list **stack_b);
int		check_pb(char *s1, char *s2, t_list **stack_a, t_list **stack_b);
int		check_pa(char *s1, char *s2, t_list **stack_a, t_list **stack_b);
int		check_rotate(char *tab, t_elemnts *elem);
void	init_elements(t_elemnts *vars, int size);
void	fill_stacks(t_elemnts *elems, char **av);
int		ft_strlen(char *str);
int		check_ra(char *s1, char *s2, t_list **stack_a);
int		check_rb(char *s1, char *s2, t_list **stack_b);
int		check_rr(char *s1, char *s2, t_list **stack_a, t_list **stack_b);
int		check_rra(char *s1, char *s2, t_list **stack_a);
int		check_rrb(char *s1, char *s2, t_list **stack_b);
int		check_rrr(char *s1, char *s2, t_list **stack_a, t_list **stack_b);
#endif
