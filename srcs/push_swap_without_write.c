/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_without_write.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:05:26 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 18:21:17 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_ps *list)
{
	int	temp;

	temp = 0;
	if (list->size >= 2)
	{
		temp = list->array[0];
		list->array[0] = list->array[1];
		list->array[1] = temp;
	}
}

void	swap_each(t_ps *s_a, t_ps *s_b)
{
	swap(s_a);
	swap(s_b);
}

void	push(t_ps *list_first, t_ps *list_second)
{
	int	removed;
	int	i;
	int	j;

	if (list_first->size == 0)
		return ;
	removed = list_first->array[0];
	i = 0;
	while (i < list_first->size - 1)
	{
		list_first->array[i] = list_first->array[i + 1];
		i++;
	}
	list_first->size = list_first->size - 1;
	j = list_second->size;
	while (j > 0)
	{
		list_second->array[j] = list_second->array[j - 1];
		j--;
	}
	list_second->array[0] = removed;
	list_second->size = list_second->size + 1;
}
