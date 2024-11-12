/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:44:19 by lsilva-x          #+#    #+#             */
/*   Updated: 2024/11/12 18:53:19 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int open_file(char *file_name)
{
	int		fd_response;

	fd_response = 0;
	fd_response = open(file_name, O_RDONLY);
	if(fd_response < 0)
	{
		printf("Invalid name file");
		return (-1);
	}
	return (fd_response);
}

int main(void)
{
	char	*file_name;
	char	*line;
	int		fd;

	line = NULL;
	file_name = "./text.txt";
	fd = open_file(file_name);
	if(!fd)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
}