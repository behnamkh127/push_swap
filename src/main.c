/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekhodad <bekhodad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:53:02 by bekhodad          #+#    #+#             */
/*   Updated: 2023/11/04 16:01:13 by bekhodad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (1);
	init_links(&a, &b, av, ac);
	if (check_greater(av, ac) || find_index(a) == 0 || check_digits(av, ac))
	{
		ft_printf("Error\n");
		free_func(&a, &b);
		return (1);
	}
	if (check_if_stack_is_sorted(&a) == 0)
	{
		free_func(&a, &b);
		return (0);
	}
	if (ac == 4)
		sort_3nums(&a);
	else
		sort_more(&a, &b, ac);
	free_func(&a, &b);
	return (0);
}
