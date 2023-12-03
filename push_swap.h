/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:33:22 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/03 21:43:42 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_ps
{
	int *array;
	int size;
}	t_ps;

t_ps	*swap_a(t_ps *list);
t_ps	*reverse_rotate_a(t_ps *list);
t_ps	*rotate_a(t_ps *list);
void	push_a_b(t_ps *list_first, t_ps *list_second);

t_ps	*swap_b(t_ps *list);
t_ps	*rotate_b(t_ps *list);
t_ps	*reverse_rotate_b(t_ps *list);
void	push_b_a(t_ps *list_first, t_ps *list_second);

int     parse_args(t_ps *stack_a, t_ps *stack_b, int argc, char **argv);
void	three_num_sort(t_ps *stack_a, int a, int b, int c);
void	two_num_sort(t_ps *stack_a, int a, int b);
void    two_stack_sort(t_ps *stack_a, t_ps *stack_b);
void	array_creation(t_ps *list, int argc, char **argv);

#endif