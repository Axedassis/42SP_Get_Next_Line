/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:44:20 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/13 13:29:34 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	if (!s)
		return (0);
	if (c == '\0')
		return ((void *)0);
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == uc)
		return ((char *)&s[i]);
	return ((void *)0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	index;

	src_length = ft_strlen(src);
	index = 0;
	if (size == 0)
		return (src_length);
	while (index != (size - 1) && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (src_length);
}

char	*ft_strjoin_gnl(char *buffer, char *line)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	total_length;

	if (!buffer)
	{
		buffer = (char *)malloc(1 * sizeof(char));
		buffer[0] = '\0';
	}
	if (!buffer || !line)
		return (NULL);
	total_length = ft_strlen(buffer) + ft_strlen(line) + 1;
	str = (char *)malloc(total_length * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (buffer[++i] != '\0')
		str[i] = buffer[i];
	while (line[j] != '\0')
		str[i++] = line[j++];
	str[i] = '\0';
	free(buffer);
	return (str);
}
