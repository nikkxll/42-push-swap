/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:46:34 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/02 15:12:27 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <ctype.h>
//	int isascii(int c);

// DESCRIPTION
//	The isascii() function tests for an ASCII character, which is any 
//	character between 0 and octal 0177 inclusive.

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (1);
	else
		return (0);
}
