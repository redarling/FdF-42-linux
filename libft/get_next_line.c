/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyvash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:55:01 by asyvash           #+#    #+#             */
/*   Updated: 2024/02/04 15:21:58 by asyvash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*del_line(char *old_buffer, size_t i)
{
	char	*new_buffer;

	if (!old_buffer[i])
	{
		free(old_buffer);
		return (NULL);
	}
	new_buffer = malloc(ft_strlen(old_buffer) - i);
	if (!new_buffer)
		return (NULL);
	ft_strcpy(new_buffer, &old_buffer[i + 1]);
	free(old_buffer);
	return (new_buffer);
}

static char	*get_line(char *buffer, size_t i)
{
	char	*line;
	size_t	j;

	if (!buffer[0])
		return (NULL);
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i++] = '\0';
	return (line);
}

static char	*read_file(int fd, char *file_content)
{
	char	*read_buffer;
	int		bytes;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(read_buffer);
			free(file_content);
			return (NULL);
		}
		read_buffer[bytes] = '\0';
		file_content = ft_strjoin_free(file_content, read_buffer, bytes);
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (file_content);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res_line;
	size_t		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	res_line = get_line(buffer, i);
	buffer = del_line(buffer, i);
	return (res_line);
}
