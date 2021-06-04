/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:35:04 by aaparici          #+#    #+#             */
/*   Updated: 2021/02/01 18:37:11 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		uc;
	const unsigned char	*su;

	uc = c;
	su = (const unsigned char *)s;
	while (n--)
		if (*su++ == uc)
			return ((void *)(su - 1));
	return (NULL);
}
