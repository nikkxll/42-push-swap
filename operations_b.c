/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:33:13 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/02 18:12:21 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap_b(t_list **list)
{
	t_list	*first;
	t_list	*second;

	if (*list == NULL || (*list)->next == NULL)
		return (NULL);
	first = *list;
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	*list = second;
	write(1, "sb\n", 3);
	return (*list);
}

t_list	*rotate_b(t_list **list)
{
	t_list	*first;
	int		*content;

	if (*list == NULL || (*list)->next == NULL)
		return (NULL);
	content = (*list)->content;
	*list = (*list)->next;
	first = *list;
	while (first->next != NULL)
	{
		first = first->next;
	}
	ft_lstadd_back(&first, ft_lstnew(content));
	write(1, "rb\n", 3);
	return (*list);
}

t_list	*reverse_rotate_b(t_list **list)
{
	t_list	*last;
	t_list	*second_last;

	if (*list == NULL || (*list)->next == NULL)
		return (NULL);
	last = *list;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *list;
	*list = last;
	write(1, "rrb\n", 4);
	return (*list);
}

void	push_b_a(t_list **list_first, t_list **list_second)
{
	int	*new_content;

	new_content = (*list_first)->content;
	*list_first = (*list_first)->next;
	ft_lstadd_front(list_second, ft_lstnew(new_content));
	write(1, "pa\n", 3);
}
