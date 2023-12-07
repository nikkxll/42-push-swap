/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_array_creation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:43:55 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/07 18:43:58 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_support(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	selection_sort(t_ps *support)
{
	int	i;
	int	min_index;
	int	j;

	i = 0;
	while (i < support->size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < support->size)
		{
			if (support->array[j] < support->array[min_index])
				min_index = j;
			j++;
		}
		if (min_index != i)
			swap_support(&support->array[i], &support->array[min_index]);
		i++;
	}
}

void	support_array_creation(t_ps *support, t_ps *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		support->array[i] = stack_a->array[i];
		i++;
	}
	support->size = stack_a->size;
	selection_sort(support);
}
