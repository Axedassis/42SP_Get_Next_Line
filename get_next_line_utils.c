/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:05:11 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/12 19:28:50 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	index;

	src_length = 0;
	while (src[src_length])
		src_length++;
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

char	*ft_strdup(const char *s)
{
	int		str_length;
	char	*str_p;

	str_length = ft_strlen(s);
	str_p = (char *)malloc((str_length + 1) * sizeof(char));
	if (!str_p)
		return ((void *)0);
	ft_strlcpy(str_p, s, str_length + 1);
	return (str_p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		length_s1;
	size_t		length_s2;
	char		*strjoin;

	if (!s1 || !s2)
		return (NULL);
	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	strjoin = (char *)malloc((length_s1 + length_s2 + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	ft_strlcpy(strjoin, s1, length_s1 + 1);
	ft_strlcpy(strjoin + length_s1, s2, length_s2 + 1);
	return (strjoin);
}
