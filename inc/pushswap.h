/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:47:23 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/04 16:14:10 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/ft_printf/includes/ft_printf.h"
# include "../lib/libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				cost_a;
	int				cost_b;
	int				tar_pos;
	int				total_cost;
	struct s_stack	*next;
}	t_stack;

// filling stack a
void		add_new(t_stack *next, char *av);
void		ps_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ps_lstnew(int content);
t_stack		*ps_lstlast(t_stack *lst);

//finding index
int			find_index(t_stack *a);
int			ps_lstsize(t_stack *lst);
void		sort_array(int *array, int size);
void		fill_index(t_stack *a, int *array, int size);
int			if_there_is_equal(int *array, int size);

//movements a
void		ra(t_stack **a);
void		rra(t_stack **a);
void		sa(t_stack **a);
void		pb(t_stack **a, t_stack **b);

//movement b
void		rb(t_stack **b);
void		rrb(t_stack **b);
void		sb(t_stack **b);
void		pa(t_stack **b, t_stack **a);

//both movement
void		rrr(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);

//if there is 3 numbers
void		sort_3nums(t_stack **a);
void		init_links(t_stack **a, t_stack **b, char **av, int ac);

//find positions
void		find_position(t_stack **s);
void		tar_pos_find(t_stack **a, t_stack **b);
int			is_suprior_index(t_stack **a, t_stack **b);
int			find_min_index(t_stack **a);
t_stack		*exact_tar_pos(t_stack *a, t_stack *b);

//sorting more than three number
void		sort_more(t_stack **a, t_stack **b, int ac);
void		do_push(t_stack **b, t_stack **a, int min);
void		do_push1(t_stack **a, t_stack **b, t_stack *temp);
void		final_sort(t_stack **a);

//do functions
void		do_push2(t_stack **a, t_stack **b, t_stack *temp);
void		do_push3(t_stack **a, t_stack *temp);
void		do_push4(t_stack **b, t_stack *temp);
void		do_push5(t_stack **b, t_stack *temp);
void		do_push6(t_stack **a, t_stack *temp);

//cost calculating
void		cost_b(t_stack **b);
void		cost_a(t_stack **b, t_stack **a);
int			make_pos(int i);
int			total_cost(t_stack **b, t_stack **a);

//error_handle
void		free_func(t_stack **a, t_stack **b);
int			check_digits(char **av, int ac);
int			check_if_stack_is_sorted(t_stack **a);
int			check_greater(char **av, int ac);
long int	atoi_plus(char *nb);

#endif
