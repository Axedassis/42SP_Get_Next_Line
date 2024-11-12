/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:04:59 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/12 19:31:18 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static int	gnl_update_buffer(char **buffer, char **line)
{
	char	*tmp_buffer;
	int		i;

	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	if ((*buffer)[i] == '\n')
	{
		(*buffer)[i] = '\0';
		tmp_buffer = ft_strjoin(*line, *buffer);
		if (!tmp_buffer)
			return (-1);
		free(*line);
		*line = tmp_buffer;
		tmp_buffer = ft_strdup(&(*buffer)[i + 1]);
		if (!tmp_buffer)
			return (-1);
		free(*buffer);
		*buffer = tmp_buffer;
		return (1);
	}
	else if (*buffer && (*buffer)[i] == '\0')
	{
		tmp_buffer = ft_strjoin(*line, *buffer);
		if (!tmp_buffer)
			return (-1);
		free(*line);
		*line = tmp_buffer;
		free(*buffer);
		*buffer = NULL;
		return (0);
	}
	return (0);
}

static int	gnl_read_file(char **buffer, char **line, int fd)
{
	char	*heap;
	char	*tmp_buffer;
	int		cnt;

	heap = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!heap)
		return (-1);
	cnt = read(fd, heap, BUFFER_SIZE);
	while (cnt > 0)
	{
		heap[cnt] = '\0';
		if (*buffer)
		{
			tmp_buffer = ft_strjoin(*buffer, heap);
			if (!tmp_buffer)
			{
				free(heap);
				return (-1);
			}
			free(*buffer);
			*buffer = tmp_buffer;
		}
		else
		{
			*buffer = ft_strdup(heap);
			if (!*buffer)
			{
				free(heap);
				return (-1);
			}
		}
		if (gnl_update_buffer(buffer, line) == 1)
		{
			free(heap);
			return (1);
		}
		cnt = read(fd, heap, BUFFER_SIZE);
	}
	free(heap);
	if (cnt == -1)
		return (-1);
	if (*buffer && **buffer != '\0')
		return (gnl_update_buffer(buffer, line));
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			cnt;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	if (buffer)
		if (gnl_update_buffer(&buffer, &line) == 1)
			return (line);
	cnt = gnl_read_file(&buffer, &line, fd);
	if (cnt == -1)
	{
		free(line);
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
