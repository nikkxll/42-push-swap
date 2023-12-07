/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriinikiforov <dmitriinikiforov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:57:03 by dnikifor          #+#    #+#             */
/*   Updated: 2023/12/08 00:44:21 by dmitriiniki      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy_newl_copy(char *src, char *dest)
{
	size_t		i;
	char		*ptr;

	ptr = dest;
	i = 0;
	while (src[i] != '\n' && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ptr);
}

char	*ft_strcpy_curr_line(char *src)
{
	size_t		i;
	char		*ptr;
	char		*dest;

	i = 0;
	if (!src || src[0] == '\0')
		return (NULL);
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	dest = NULL;
	if (src[i] == '\n')
		dest = malloc((i + 2) * sizeof(char));
	else
		dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ptr = ft_strcpy_newl_copy(src, dest);
	return (ptr);
}

char	*ft_strcpy_remainder(char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	if (!src[i])
		return (ft_free(src));
	dest = malloc((ft_strlen(src) - i + 1) * sizeof(char));
	if (!dest)
		return (ft_free(src));
	i++;
	while (src[i] != '\0')
		dest[j++] = src[i++];
	dest[j] = '\0';
	if (!dest[0])
	{
		free(dest);
		return (ft_free(src));
	}
	free(src);
	return (dest);
}

char	*str_extractor(char *text_runner, int fd)
{
	ssize_t			bytes;
	char			*buffer;

	bytes = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(text_runner));
	while (!ft_strchr(text_runner, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (ft_free(text_runner));
		}
		buffer[bytes] = '\0';
		text_runner = ft_strjoin_gnl(text_runner, buffer);
		if (!text_runner)
			return (ft_free(buffer));
	}
	free(buffer);
	return (text_runner);
}

char	*get_next_line(int fd)
{
	char		*current_line;
	static char	*text_runner;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= (size_t)(-2))
		return (NULL);
	text_runner = str_extractor(text_runner, fd);
	if (!text_runner)
	{
		text_runner = NULL;
		return (NULL);
	}
	current_line = ft_strcpy_curr_line(text_runner);
	if (!current_line)
	{
		text_runner = ft_free(text_runner);
		return (NULL);
	}
	text_runner = ft_strcpy_remainder(text_runner);
	return (current_line);
}
