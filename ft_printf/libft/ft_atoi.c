/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:17:52 by aaparici          #+#    #+#             */
/*   Updated: 2021/04/12 12:10:09 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	unsigned long	acc;
	int				sign;

	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	sign = 1;
	if (*s == '-')
		sign = -1;
	if ((*s == '-') || (*s == '+'))
		s++;
	acc = 0;
	while (ft_isdigit(*s))
	{
		if (acc >= LONG_MAX / 10)
		{
			if (sign < 0 )
				return (sign * LONG_MIN);
			else
				return (sign * LONG_MAX);
		}
		else
			acc = acc * 10 + *s - '0';
		s++;
	}
	return (sign * acc);
}
