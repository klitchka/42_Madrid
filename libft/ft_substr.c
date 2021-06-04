/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:30:12 by aaparici          #+#    #+#             */
/*   Updated: 2021/02/09 11:30:14 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*r;
	size_t	s_len;

	i = 0;
	if (!s || (long int)len < 0)
		return (NULL);
	s_len = s ? ft_strlen(s) : 0;
	if (start >= s_len)
		len = 0;
	r = (char *)malloc(len + 1);
	if (r == NULL)
		return (NULL);
	while (s[start + i] && i < len)
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
