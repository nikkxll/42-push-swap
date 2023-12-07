/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:33:22 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:42:26 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/libft/get_next_line.h"

typedef struct s_ps
{
	int	*array;
	int	size;
}	t_ps;

int		find_max_num_index(t_ps *stack_b, int max);
int		find_min_number(t_ps *stack_b);
int		find_max_number(t_ps *stack_b);
int		find_top(t_ps *stack_a, t_ps *support, int range_max, int start);
int		find_bottom(t_ps *stack_a, t_ps *support, int range_max, int start);

int		msg_memory_free(t_ps *stack_a, t_ps *stack_b);

int		check_if_sorted(t_ps *stack_a);
void	push_back(t_ps *stack_a, t_ps *stack_b);
void	mini_sort(t_ps *stack_a, t_ps *stack_b);

void	three_num_sort(t_ps *list, int a, int b, int c);
void	three_num_desc_sort_b(t_ps *list, int a, int b, int c);
void	two_num_sort(t_ps *stack_a, int a, int b);

void	rotate_a(t_ps *list);
void	reverse_rotate_a(t_ps *list);
void	rotate_b(t_ps *list);
void	reverse_rotate_b(t_ps *list);

void	swap_a(t_ps *list);
void	swap_b(t_ps *list);
void	push_a_b(t_ps *list_first, t_ps *list_second);
void	push_b_a(t_ps *list_first, t_ps *list_second);

int		array_creation(t_ps *stack_a, t_ps *stack_b, int argc, char **argv);

void	rotate(t_ps *list);
void	reverse_rotate(t_ps *list);

void	rotation_steps(int *rotations);

void	sort(t_ps *stack_a, t_ps *stack_b, t_ps *support);

void	support_array_creation(t_ps *support, t_ps *stack_a);

void	rot_a_condition(t_ps *stack_a, int c_i, int temp, int *rotations);
void	rot_b_condition(t_ps *stack_b, int i, int *rotations);
void	set_rotation_min_max(t_ps *stack_b, int min, int max, int *rotations);
void	rotate_back(t_ps *stack_b);
int		set_rotation(t_ps *stack_a, t_ps *stack_b, int min, int max);

#endif