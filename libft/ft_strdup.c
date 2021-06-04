/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:29:38 by aaparici          #+#    #+#             */
/*   Updated: 2021/02/09 11:29:40 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*d;

	len = ft_strlen(str) + 1;
	d = (char *)malloc(sizeof(char) * len);
	if (d)
		ft_memcpy(d, str, len);
	return (d);
}
