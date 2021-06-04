/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:28:08 by aaparici          #+#    #+#             */
/*   Updated: 2021/04/11 19:51:58 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Locate the first occurrence of a character in string
** The terminating null character is considered to be part of the string; 
** therefore if c is `\0', the functions locate the terminating `\0'.
** Return: 
** a pointer to the located character, or NULL if the character
** does not appear in the string.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)--s);
	if (!c)
		return ((char *)s);
	return (NULL);
}
