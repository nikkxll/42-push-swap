/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:33:22 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/04 20:42:59 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_ps
{
	int	*array;
	int	size;
}	t_ps;

t_ps	*swap_a(t_ps *list);
t_ps	*reverse_rotate_a(t_ps *list);
t_ps	*rotate_a(t_ps *list);
void	push_a_b(t_ps *list_first, t_ps *list_second);

t_ps	*swap_b(t_ps *list);
t_ps	*rotate_b(t_ps *list);
t_ps	*reverse_rotate_b(t_ps *list);
void	push_b_a(t_ps *list_first, t_ps *list_second);

int		array_creation(t_ps *stack_a, t_ps *stack_b, int argc, char **argv);
void	three_num_sort(t_ps *stack_a, int a, int b, int c);
void	two_num_sort(t_ps *stack_a, int a, int b);
void	mini_sort(t_ps *stack_a, t_ps *stack_b);
void	support_array_creation(t_ps *support, t_ps *stack_a);
void	sort(t_ps *stack_a, t_ps *stack_b, t_ps *support);
int		check_if_sorted(t_ps *stack_a);
int		find_max_number(t_ps *stack_b);
void	push_back(t_ps *stack_a, t_ps *stack_b);
void	three_num_desc_sort_b(t_ps *list, int a, int b, int c);

#endif