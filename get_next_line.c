/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:44:19 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/13 20:08:27 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*get_line(char *buffer, int fd)
{
	char	*line;
	int		cnt;

	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	cnt = 1;
	if (!line)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && cnt != 0)
	{
		cnt = read(fd, line, BUFFER_SIZE);
		if (cnt == -1 || (cnt == 0 && !buffer))
		{
			free(line);
			return (NULL);
		}
		line[cnt] = '\0';
		buffer = ft_strjoin_gnl(buffer, line);
	}
	free(line);
	return (buffer);
}

char	*get_content(char *line)
{
	size_t	line_size;
	char	*content;

	line_size = 0;
	if (!line)
		return (NULL);
	while (line[line_size] != '\n' && line[line_size])
		line_size++;
	content = (char *)malloc((line_size + 2) * sizeof(char));
	if (!content)
		return (NULL);
	line_size = 0;
	while (line[line_size] != '\n' && line[line_size])
	{
		content[line_size] = line[line_size];
		line_size++;
	}
	if (line[line_size] == '\n')
		content[line_size] = '\n';
	content[line_size + 1] = '\0';
	return (content);
}

char	*get_rest(char *buffer)
{
	char	*rest;
	int		s_line;
	int		y;

	s_line = 0;
	y = 0;
	while (buffer[s_line] != '\n' && buffer[s_line])
		s_line++;
	if (!buffer[s_line])
	{
		free(buffer);
		return (NULL);
	}
	rest = (char *)malloc((ft_strlen(buffer) - s_line) * sizeof(char));
	if (!rest)
		return (NULL);
	s_line++;
	while (buffer[s_line])
		rest[y++] = buffer[s_line++];
	rest[y] = '\0';
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_line(buffer, fd);
	if (!buffer)
		return (NULL);
	line = get_content(buffer);
	buffer = get_rest(buffer);
	return (line);
}
