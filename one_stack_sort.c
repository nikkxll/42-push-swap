/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_stack_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:50:40 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/04 20:43:11 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_num_sort(t_ps *list, int a, int b, int c)
{
	if (a < b && b < c && a < c)
		return ;
	else if (a < b && b > c && a < c)
	{
		reverse_rotate_a(list);
		swap_a(list);
	}
	else if (a > b && b < c && a < c)
		swap_a(list);
	else if (a < b && b > c && a > c)
		reverse_rotate_a(list);
	else if (a > b && b < c && a > c)
		rotate_a(list);
	else
	{
		swap_a(list);
		reverse_rotate_a(list);
	}
}

void	three_num_desc_sort_b(t_ps *list, int a, int b, int c)
{
	if (a < b && b < c && a < c)
	{
		swap_b(list);
		reverse_rotate_b(list);
	}
	else if (a < b && b > c && a < c)
		rotate_b(list);
	else if (a > b && b < c && a < c)
		reverse_rotate_b(list);
	else if (a < b && b > c && a > c)
		swap_b(list);
	else if (a > b && b < c && a > c)
	{
		reverse_rotate_b(list);
		swap_b(list);
	}
	else
		return ;
}

void	two_num_sort(t_ps *stack_a, int a, int b)
{
	if (a < b)
		return ;
	else
		swap_a(stack_a);
}
