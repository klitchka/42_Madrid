/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:18:09 by aaparici          #+#    #+#             */
/*   Updated: 2021/02/15 16:18:12 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int num)
{
	char			*s;
	int				len;
	int				minus;
	unsigned int	un;

	len = num > 0 ? 0 : 1;
	un = num > 0 ? num : -num;
	minus = num < 0 ? 1 : 0;
	while (un > 0)
	{
		un /= 10;
		len++;
	}
	if ((s = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	s[len] = '\0';
	if (minus)
		s[0] = '-';
	while (len-- > minus)
	{
		s[len] = '0' + num % 10 * (num < 0 ? -1 : 1);
		num /= 10;
	}
	return (s);
}
