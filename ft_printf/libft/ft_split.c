/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:29:17 by aaparici          #+#    #+#             */
/*   Updated: 2021/04/12 12:19:48 by aaparici         ###   ########.fr       */
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
	const char	*sc;

	sc = s;
	while (*sc != c && *sc++)
		;
	return ((unsigned int)(sc - s));
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (numw(s, c) + 1));
	if (!tab)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			tab[j++] = ft_strndup(s, lenw(s, c));
			while (*s && *s != c)
				s++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
