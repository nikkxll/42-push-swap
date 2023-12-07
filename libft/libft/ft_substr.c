/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:52:28 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/02 15:13:02 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype: char *ft_substr(char const *s, unsigned int start,
// size_t len);

// Turn in files: -

// Parameters: s: The string from which to create the substring.
// 			   start: The start index of the substring in the
// string ’s’.
// 			   len: The maximum length of the substring.

// Return value: The substring.
// NULL if the allocation fails.

// External functs.: malloc

// Description: Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*subs;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
			subs[j++] = s[i];
		i++;
	}
	subs[j] = 0;
	return (subs);
}
