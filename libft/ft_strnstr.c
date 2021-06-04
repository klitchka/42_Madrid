/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:19:13 by aaparici          #+#    #+#             */
/*   Updated: 2021/02/15 16:19:14 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len-- > 0)
	{
		j = 0;
		while (haystack[j] == needle[j] && j++ <= len)
			if (!needle[j])
				return ((char *)haystack);
		haystack++;
	}
	return (0);
}
