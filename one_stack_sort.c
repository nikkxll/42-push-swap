/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_stack_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:50:40 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/02 18:03:11 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one_stack_sort(t_list *stack_a)
{
	int	*a;
	int	*b;
	int	*c;

	if (ft_lstsize(stack_a) == 1)
		return ;
	a = stack_a->content;
	b = stack_a->next->content;
	c = stack_a->next->next->content;
	if (*a < *b && *b < *c && *a < *c)
		return ;
	else if (*a < *b && *b > *c && *a < *c)
	{
		reverse_rotate_a(&stack_a);
		swap_a(&stack_a);
	}
	else if (*a > *b && *b < *c && *a < *c)
		swap_a(&stack_a);
	else if (*a < *b && *b > *c && *a > *c)
		reverse_rotate_a(&stack_a);
	else if (*a > *b && *b < *c && *a > *c)
		rotate_a(&stack_a);
	else
	{
		swap_a(&stack_a);
		reverse_rotate_a(&stack_a);
	}
}
