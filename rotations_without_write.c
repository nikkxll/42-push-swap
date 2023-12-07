/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_without_write.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:27:09 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/07 18:25:29 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_ps *list)
{
	int	temp;
	int	i;

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
}

void	reverse_rotate(t_ps *list)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	if (list->size > 1)
	{
		temp = list->array[list->size - 1];
		i = list->size - 1;
		while (i > 0)
		{
			list->array[i] = list->array[i - 1];
			i--;
		}
		list->array[0] = temp;
	}
}
