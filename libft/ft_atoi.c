/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:17:52 by aaparici          #+#    #+#             */
/*   Updated: 2021/02/15 16:19:54 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	unsigned long	acc;
	int				sign;
	int				any;

	while (*s == '\t' || *s == '\n' || *s == '\v' || *s == '\f' || *s == '\r' ||
			*s == ' ')
		s++;
	sign = 1;
	if (*s == '-')
		sign = -1;
	if ((*s == '-') || (*s == '+'))
		s++;
	acc = 0;
	any = 1;
	while (ft_isdigit(*s))
	{
		if (any < 0 || acc >= LONG_MAX / 10)
			any = -1;
		else
			acc = acc * 10 + *s - '0';
		s++;
	}
	if (any < 0)
		acc = sign < 0 ? LONG_MIN : LONG_MAX;
	return (sign * acc);
}
