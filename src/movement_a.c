/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:54:31 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/01 16:50:45 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*second;

	first = *a;
	second = (*a)->next;
	temp = *a;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	*a = second;
}

void	rra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*last;

	first = *a;
	temp = *a;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = first;
	*a = last;
}

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	first = *a;
	second = first->next;
	*a = second;
	first->next = second->next;
	second->next = first;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a)
		exit (0);
	if (b == NULL)
	{
		b = a;
		(*b)->next = NULL;
	}
	else
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
	}
	ft_printf("pb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
