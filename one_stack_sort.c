/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_stack_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:50:40 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/03 19:05:01 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_num_sort(t_ps *stack_a, int a, int b, int c)
{
	if (a < b && b < c && a < c)
		return ;
	else if (a < b && b > c && a < c)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (a > b && b < c && a < c)
		swap_a(stack_a);
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack_a);
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
}

void	two_num_sort(t_ps *stack_a, int a, int b)
{
	if (a < b)
		return ;
	else 
		swap_a(stack_a);
}
