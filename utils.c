/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:24:34 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/02 18:09:33 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	linked_list_node_add(t_list **list, void *value)
{
	t_list	*new_node;

	new_node = ft_lstnew(value);
	ft_lstadd_back(list, new_node);
}
