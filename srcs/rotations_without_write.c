/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_without_write.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:27:09 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 18:21:28 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	rotate_each(t_ps *s_a, t_ps *s_b)
{
	rotate(s_a);
	rotate(s_b);
}

void	reverse_rotate_each(t_ps *s_a, t_ps *s_b)
{
	reverse_rotate(s_a);
	reverse_rotate(s_b);
}
