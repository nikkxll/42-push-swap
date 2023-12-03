/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:33:13 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/03 18:59:44 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*swap_a(t_ps *list)
{
	int temp;

	temp = 0;
    if (list->size >= 2) 
	{
        temp = list->array[0];
        list->array[0] = list->array[1];
        list->array[1] = temp;
    }
	write(1, "sa\n", 3);
	return (list);
}

t_ps	*rotate_a(t_ps *list) 
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
	return (list);
}

t_ps	*reverse_rotate_a(t_ps *list)
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
	return (list);
}

void	push_a_b(t_ps *list_first, t_ps *list_second)
{
	int removedElement;
	int i;
	int j;
	
    if (list_first->size == 0)
        return ;
    removedElement = list_first->array[0];
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
    list_second->array[0] = removedElement;
    list_second->size = list_second->size + 1;
	write(1, "pb\n", 3);
}
