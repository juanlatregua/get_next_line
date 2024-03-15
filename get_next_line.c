/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:37:21 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/03/11 11:54:16 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//	function that reads the file
//	stores the string in the buffer and joins it to the stash
// returns the number of bytes read from the file 
// if the number of bytes read is less than 0 or the buffer is NULL, 
// the function frees the stash and sets it to NULL because there was an error reading the file 
// if the number of bytes read is 0, the function returns 0 because the file is empty or the end of the file was reached.
// the function joins the buffer to the stash and returns the number of bytes read from the file
// if the join fails, the function frees the stash and sets it to NULL and returns -1
// the function returns the number of bytes read from the file
// tmp is used to store the result of the join between the stash and the buffer 
// stash is freed and set to NULL  
// stash is set to tmp because the join was successful 
// I have to free the stash every time I use it because I don't want to have memory leaks 
// return the number of bytes read from the file to the function get_next_line and store it in the variable 
// bytes because we need to read the file at least once if is 0 the file is empty
// the resume of the function is the number of bytes read from the file 
// if the number of bytes read is less than 0 or the buffer is NULL, the function frees the stash and sets it to NULL because there was an error reading the file
// if the number of bytes read is 0, the function returns 0 because the file is empty or the end of the file was reached.
// the function joins the buffer to the stash and returns the number of bytes read from the file
// if the join fails, the function frees the stash and sets it to NULL and returns -1
// the function returns the number of bytes read from the file
// tmp is used to store the result of the join between the stash and the buffer
// stash is freed and set to NULL
// stash is set to tmp because the join was successful 
// I have to free the stash every time I use it because I don't want to have memory leaks. 
// Memory leaks are bad because they can cause the program to crash or run out of memory

static int	read_buffer(int fd, char **stash, char *buffer)
{
	char	*tmp;
	int		bytes;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0 || buffer == NULL)
	{
		free(*stash);
		*stash = NULL;
		return (-1);
	}
	if (bytes == 0)
		return (bytes);
	tmp = ft_strjoin(*stash, buffer);
	if (tmp == NULL)
	{
		free(*stash);
		*stash = NULL;
		return (-1);
	}
	free(*stash);
	*stash = tmp;
	return (bytes);
}

//	Removes the string obtained in get_result()
//	from the stash.
// If the string obtained is NULL, the function does nothing
// nl is used to store the position of the first '\n' character in the stash
// tmp is used to store the result of the join between the stash and the buffer
// i is used to iterate through the stash
// j is used to iterate through the stash
//  malloc is used to allocate memory for the new string we use ft_strlen to get the length of the new string 
// *sizeof(char) is used to get the size of the new string in bytes 
// the new string is filled with the characters of the stash after the '\n' character
// the new string is freed and set to NULL
// the stash is set to the new string
// if the stash is empty, the stash is freed and set to NULL
// the function returns nothing
// ft_strlen - ft_strlen(nl) + 1 is used to get the length of the new string 


static void	remove_result(char **stash)
{
	char	*nl;
	char	*tmp;
	size_t	i;
	size_t	j;

	nl = ft_strchr(*stash, '\n');
	if (!nl)
	{
		free(*stash);
		*stash = NULL;
		return ;
	}
	tmp = malloc((ft_strlen(nl)) * sizeof(char));
	i = 0;
	j = ft_strlen(*stash) - ft_strlen(nl) + 1;
	while (j < ft_strlen(*stash))
		tmp[i++] = (*stash)[j++];
	tmp[i] = '\0';
	free(*stash);
	*stash = tmp;
	if (**stash == 0)
	{
		free(*stash);
		*stash = NULL;
	}
}

//	Stores the string obtained from the stash in the result
//	Allocates memory for the result
//	**result is used to store the string obtained from the stash
// **stash is used to store the string read from the file
// *result is used to store the string to return
// *stash is used to store the string read from the file
// nl is used to store the position of the first '\n' character in the stash
// len is used to store the length of the string to return
// i is used to iterate through the string to return
// malloc is used to allocate memory for the string to return, 
// we use ft_strlen to get the length of the string to return
// *sizeof(char) is used to get the size of the string to return in bytes
// the if statement is used to check if the allocation of memory for the string to return was successful
// the while loop is used to fill the string to return with the characters of the stash 
// i is used to iterate through the string to return *result[i] is used to store the characters of the stash in the string to return
// i is incremented after storing the character in the string to return
// *result[i] is set to '\0' to indicate the end of the string to return 
//because the string to return is a C string and it needs to be null-terminated
// the function returns nothing 
// static void	get_result(char **stash, char **result) 
// is used to get the string to return from the stash and store it in result.
// I use **stash and the *stash because I need to modify the stash 
// and I use **result and the *result because I need to modify the result. 
// Thats means I need to use the address of the result and the stash to modify them 
// because I need to modify the stash and the result to get the string to return from the stash and store it in result.
// the double pointer is used to modify the stash and the result 
// because I need to modify the stash and the result to get the string to return from the stash and store it in result.
// why I need two variables to store the string to return and the string read from the file? 
// I need two variables to store the string to return and the string read from the file 
// because I need to store the string to return and the string read from the file in two different variables. 

// The first variable stash is used to store the string read from the file
// the second variable result is used to store the string to return
// the function returns nothing
// The double pointer is used to modify the stash and the result 
// because I need to modify the stash and the result to get the string to return from the stash and store it in result. 
// If I use the single pointer I can't modify the stash and the result. How can I modify the stash and the result? 
// I modify the stash and the result using the double pointer because I need to modify the stash and 
// the result to get the string to return from the stash and store it in result.
// len is used to store the length of the string to return. ft_strlen is used to get the length of *stash - ft_strlen(nl) + 2 
// and the len from *stash is used to get the length of the string to return and 
// we - ft_strlen(n) because we need to get the length of the string to return and 
// we + 2 because we need to add 2 bytes to the length of the string to return 
// because we need to add 1 byte for the '\n' character and 1 byte for the '\0' character
// then we use malloc to allocate memory for the string to return using len * sizeof(char) that we get from the length of the string to return
// if the allocation of memory for the string to return fails, the function returns nothing
// i is used to iterate through the string to return
// the while loop is used to fill the string to return with the characters of the stash and -1 because we need to add 1 byte for the '\n' character
// *result[i] is used to store the characters of the stash in the string to return
// i is incremented after storing the character in the string to return
// *result[i] is set to '\0' to indicate the end of the string to return. 
// Get_result is used to get the string to return from the stash and store it in result 


static void	get_result(char **stash, char **result)
{
	char	*nl;
	size_t	len;
	size_t	i;

	nl = ft_strchr(*stash, '\n');
	len = ft_strlen(*stash) - ft_strlen(nl) + 2;
	*result = (char *)malloc(len * sizeof(char));
	if (!result)
		return ;
	i = 0;
	while (i < len - 1)
	{
		(*result)[i] = (*stash)[i];
		i++;
	}
	(*result)[i] = '\0';
}
/* variable bytes to store the number of bytes read from the file
// it is set to 1 because we need to read the file at least once if is 0 the file is empty
/* variable buffer to store the string read from the file needed to store the string read from the file
 we use malloc to allocate memory for the string
/* variable result to store the string to return
/* variable stash to store the string read from the file
/* if the file descriptor is less than 0 or the buffer size is less than 0, the function returns NULL
/* buffer is allocated memory to store the string read from the file
/* bytes is set to 1 because we need to read the file at least once
/* while the '\n' character is not found in the stash and the number of bytes read is greater than 0, 
the function ft strchr is used to find the '\n' character in the stash == NULL 
is used to check if the '\n' character is not found in the stash  
and bytes > 0 is used to check if the number of bytes read is greater than 0
/* read_buffer is used to read the file and store the string in the buffer and join it to the stash 
/* buffer is freed after the while loop ends because we don't need it anymore 
/* if the number of bytes read is less than 0, the function returns NULL because there was an error reading the file
/* if the length of the stash is 0, the function returns NULL because there is no string to return 
/* get_result is used to get the string to return from the stash and store it in result 
/* remove_result is used to remove the string obtained from the stash and store the new stash 
/* the function returns the string obtained from the stash

*/
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*result;
	char		*buffer;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes = 1;
	while (ft_strchr(stash, '\n') == NULL && bytes > 0)
		bytes = read_buffer(fd, &stash, buffer);
	free(buffer);
	if (bytes == -1)
		return (NULL);
	if (ft_strlen(stash) == 0)
		return (NULL);
	get_result(&stash, &result);
	remove_result(&stash);
	return (result);
}
/*
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL) // if is NULL the file is empty and the program ends
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
*/