/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:29:17 by aaparici          #+#    #+#             */
/*   Updated: 2021/02/25 16:59:19 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	numw(const char *s, char c)
{
	size_t	nw;

	nw = 0;
	while (*s)
		if (*s++ != c && (*s == c || !*s))
			nw++;
	return (nw);
}

size_t	lenw(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s++)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	i;
	char	**tab;

	j = 0;
	if (!s || !(tab = malloc(sizeof(char *) * (numw(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			i = 0;
			if (!(tab[j] = (char *)malloc(sizeof(char) * (lenw(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				tab[j][i++] = (char)*s++;
			tab[j][i] = '\0';
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
