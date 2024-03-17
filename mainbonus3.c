/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbonus3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:03:57 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/03/17 20:15:35 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
    int		fd;
    char	*line;
    int i;

    if (argc < 2) // necesitas al menos un nombre de archivo para probar get_next_line_bonus.c
    {
        printf("Add at least one file <file1> <file2> <file3>...\n");
        return (1);
    }

    for (i = 1; i < argc; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            printf("error opening file %s\n", argv[i]);
            continue;
        }

        while ((line = get_next_line_bonus(fd)) != NULL)
        {
            printf("%s", line);
            free(line);
        }

        close(fd);
    }

    return (0);
}