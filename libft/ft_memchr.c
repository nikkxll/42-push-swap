/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:25:56 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/02 15:12:32 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SYNOPSIS
//	#include <string.h>
//	void *memchr(const void *s, int c, size_t n);

// DESCRIPTION
//	The memchr() function locates the first occurrence of c 
//	(converted to an unsigned char) in string s.

// RETURN VALUES
//	The memchr() function returns a pointer to the byte located, 
//	or NULL if no such byte exists within n bytes.

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;

	while (n > 0)
	{
		if (*p == (unsigned char)c)
		{
			return ((void *)p);
		}
		p++;
		n--;
	}
	return (0);
}
