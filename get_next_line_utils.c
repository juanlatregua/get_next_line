/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-m <jsilva-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:14:56 by jsilva-m          #+#    #+#             */
/*   Updated: 2024/03/06 15:53:24 by jsilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//	fills 'n' bytes of a memory area 's'
//	with null characters.
// If 'n' is 0, the function does nothing
// If 's' is NULL, the function does nothing
// If 'n' is NULL, the function returns NULL
// If 'n' is greater than the size of 's',  the function fills the entire string with null characters 
// If 'n' is less than the size of 's', the function fills the first 'n' bytes of the string with null characters 
// The function returns nothing 
// s cast to an unsigned char pointer to access the memory area as bytes
// you need a char pointer to access the memory area as characters and a void pointer to access the memory area as a generic pointer
// i is used to iterate through the memory area
// the memory area is filled with null characters until the end of the string is reached 

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == NULL)
		return (NULL);
	while (i < n)
	{
		*((unsigned char *)s + i) = '\0';
		i++;
	}
}

//	Calculates the lenght of a string 'str'
//	by counting the number of characters before the null character '\0' is found  
// If 'str' is NULL, the function returns 0  
// The function returns the number of characters in the string 'str'

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

//	Function that searches for a character 'c'
//	in a string 's' and returns a pointer to
//	that character
// If 's' is NULL, the function returns NULL
// If 'c' is not found in 's', the function returns NULL
// If 'c' is found in 's', the function returns a pointer to that character 
// The function returns a pointer to the character 'c' in the string 's'
// char pointer 's' is used to iterate through the string 
// if the character is found, the function returns a pointer to that character
// or NULL if the character is not found

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}

//	Function that takes 2 strings, 's1' and 's2',
//	and joins them together in a new string 'str'
// If 's1' or 's2' is NULL, the function returns NULL
// The function returns a pointer to the new string 'str'
// The function allocates memory for the new string 'str' using malloc
// The function copies the characters from 's1' and 's2' to 'str' using a while loop
// The function returns a pointer to the new string 'str'
// The function returns NULL if the memory allocation fails

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *s1)
	{
		str[i++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = '\0';
	return (str);
}
