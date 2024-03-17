/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:05:46 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/03/17 19:44:50 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = 0;
	if (argc != 2) // si no hay argumentos (nombre del archivo) muestra el mensaje.
	{
		printf("No files add <file>\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error opening file\n");
		return (1);
	}
	line = get_next_line(fd);
	printf("the string read is \"%s\" \n", line);
	line = get_next_line(fd);
	printf("the string read is \"%s\" \n", line);
	line = get_next_line(fd);
	printf("the string read is\"%s\" \n", line);

	close(fd);
	free(line);
	return (0);
}
// The output of the program should be:
// the string read is "This is the first line of the file"