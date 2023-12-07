/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:12:26 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/03 16:06:05 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_lstsize

// Prototype: int ft_lstsize(t_list *lst);

// Turn in files: -

// Parameters: lst: The beginning of the list.

// Return value: The length of the list

// External functs.: None

// Description: Counts the number of nodes in a list.

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
