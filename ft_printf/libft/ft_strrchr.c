/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:27:00 by aaparici          #+#    #+#             */
/*   Updated: 2021/04/11 20:37:08 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Locate the last occurrence of a character in string
** The terminating null character is considered to be part of the string; 
** therefore if c is `\0', the functions locate the terminating `\0'.
** Return: 
** a pointer to the located character, or NULL if the character
** does not appear in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*r;
	const char	*p;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	r = NULL;
	p = ft_strchr(s, c);
	while (p != NULL)
	{
		r = p;
		s = p + 1;
		p = ft_strchr(s, c);
	}
	return ((char *)r);
}
