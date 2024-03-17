/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:36:26 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/03/17 19:38:34 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
    int		fd1, fd2;
    char	*line;

    line = 0;
    if (argc != 3) // necesitas dos nombres de archivos para probar get_next_line_bonus.c
    {
        printf("Add two files <file1> <file2>\n");
        return (1);
    }
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);
    if (fd1 == -1 || fd2 == -1)
    {
        printf("error opening file(s)\n");
        return (1);
    }
    line = get_next_line_bonus(fd1);
    printf("the string read from file 1 is \"%s\" \n", line);
    free(line);
    line = get_next_line_bonus(fd2);
    printf("the string read from file 2 is \"%s\" \n", line);
    free(line);
    // Continúa alternando entre los archivos como desees

    close(fd1);
    close(fd2);
}