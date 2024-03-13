/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:27:58 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/01 09:57:42 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	do_push2(t_stack **a, t_stack **b, t_stack *temp)
{
	rrr(a, b);
	temp->cost_a += 1;
	temp->cost_b += 1;
	ft_printf("rrr\n");
}

void	do_push3(t_stack **a, t_stack *temp)
{
	ra(a);
	temp->cost_a -= 1;
	ft_printf("ra\n");
}

void	do_push4(t_stack **b, t_stack *temp)
{
	rb(b);
	temp->cost_b -= 1;
	ft_printf("rb\n");
}

void	do_push5(t_stack **b, t_stack *temp)
{
	rrb(b);
	temp->cost_b += 1;
	ft_printf("rrb\n");
}

void	do_push6(t_stack **a, t_stack *temp)
{
	rra(a);
	temp->cost_a += 1;
	ft_printf("rra\n");
}
