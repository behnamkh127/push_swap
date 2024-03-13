/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:25:41 by bekhodad          #+#    #+#             */
/*   Updated: 2023/10/31 14:36:26 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*second;

	first = *b;
	second = (*b)->next;
	temp = *b;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	*b = second;
}

void	rrb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*last;

	first = *b;
	temp = *b;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = first;
	*b = last;
}

void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	first = *b;
	second = first->next;
	*b = second;
	first->next = second->next;
	second->next = first;
}

void	pa(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	if (!b)
		exit (0);
	if (a == NULL)
	{
		a = b;
		(*a)->next = NULL;
	}
	else
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
