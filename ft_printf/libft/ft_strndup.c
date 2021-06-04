/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:23:19 by aaparici          #+#    #+#             */
/*   Updated: 2021/04/11 22:26:21 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t	len)
{
	char	*d;

	if (len < 0)
		return (0);
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (0);
	ft_memcpy(d, s, len);
	d[len] = '\0';
	return (d);
}
