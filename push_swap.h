/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:33:22 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/02 18:16:05 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "./libft/libft.h"

t_list	*swap_a(t_list **list);
t_list	*reverse_rotate_a(t_list **list);
t_list	*rotate_a(t_list **list);
void	push_a_b(t_list **list_first, t_list **list_second);

t_list	*swap_b(t_list **list);
t_list	*rotate_b(t_list **list);
t_list	*reverse_rotate_b(t_list **list);
void	push_b_a(t_list **list_first, t_list **list_second);

void	linked_list_node_add(t_list **list, void *value);
int		parse_args(t_list **list, int argc, char **argv);
int		*ll_creation(t_list **list, int argc, char **argv, int *array);
void	one_stack_sort(t_list *stack_a);

#endif