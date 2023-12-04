/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_array_creation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:57:24 by dmitriiniki       #+#    #+#             */
/*   Updated: 2023/12/04 11:29:59 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap_support(int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

static void selection_sort(t_ps *support) 
{
    int i;
    int minIndex;
    int j;
    
    i = 0;
    while (i < support->size - 1) {
        minIndex = i;
        j = i + 1;
        while (j < support->size) {
            if (support->array[j] < support->array[minIndex]) {
                minIndex = j;
            }
            j++;
        }
        if (minIndex != i) {
            swap_support(&support->array[i], &support->array[minIndex]);
        }
        i++;
    }
}

void support_array_creation(t_ps *support, t_ps *stack_a)
{
    int i;

    i = 0;
    while (i < stack_a->size) {
        support->array[i] = stack_a->array[i];
        i++;
    }
    support->size = stack_a->size;
    selection_sort(support);
}
