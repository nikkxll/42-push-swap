/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:06:27 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/05 19:10:05 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_ps *list) 
{
	int temp;
	int i;
	
	temp = 0;
	i = 0;
    if (list->size > 1)
	{
		temp = list->array[0];
		i = 0;
		while (i < list->size - 1)
		{
			list->array[i] = list->array[i + 1];
			i++;
		}
		list->array[list->size - 1] = temp;
	}
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_ps *list)
{
	int temp;
	int i;
	
	temp = 0;
	i = 0;
    if (list->size > 1)
	{
		temp = list->array[list->size - 1];
		i = list->size - 1;
		while (i > 0) {
			list->array[i] = list->array[i - 1];
			i--;
		}
		list->array[0] = temp;
	}
	write(1, "rra\n", 4);
}

void	rotate_b(t_ps *list) 
{
	int temp;
	int i;
	
	temp = 0;
	i = 0;
    if (list->size > 1)
	{
		temp = list->array[0];
		i = 0;
		while (i < list->size - 1)
		{
			list->array[i] = list->array[i + 1];
			i++;
		}
		list->array[list->size - 1] = temp;
	}
	write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_ps *list)
{
	int temp;
	int i;
	
	temp = 0;
	i = 0;
    if (list->size > 1)
	{
		temp = list->array[list->size - 1];
		i = list->size - 1;
		while (i > 0) {
			list->array[i] = list->array[i - 1];
			i--;
		}
		list->array[0] = temp;
	}
	write(1, "rrb\n", 4);
}