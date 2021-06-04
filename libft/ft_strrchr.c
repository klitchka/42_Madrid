/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:27:00 by aaparici          #+#    #+#             */
/*   Updated: 2021/02/17 18:27:02 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*r;
	const char	*p;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	r = NULL;
	while ((p = ft_strchr(s, c)) != NULL)
	{
		r = p;
		s = p + 1;
	}
	return ((char *)r);
}
