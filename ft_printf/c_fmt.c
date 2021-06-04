/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_fmt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:51:24 by aaparici          #+#    #+#             */
/*   Updated: 2021/05/17 13:50:08 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_pre(t_mod *m)
{
	int	np;

	np = 0;
	if (m->adj || m->padd == '0')
	{
		if (m->sign)
			np += write(1, &m->sign, 1);
		if (m->c == 'p')
		{
			if (m->c == 'X')
				np += write(1, "0X", 2);
			else
				np += write(1, "0x", 2);
		}
	}
	return (np);
}

int	fmt_pos(t_mod *m)
{
	int	np;

	np = 0;
	if (!m->adj && m->padd == ' ')
	{
		if (m->sign)
			np += write(1, &m->sign, 1);
		if (m->c == 'p')
		{
			if (m->c == 'X')
				np += write(1, "0X", 2);
			else
				np += write(1, "0x", 2);
		}
	}
	return (np);
}

int	fmt_padd(t_mod *m, int len)
{
	int	np;

	np = 0;
	if (m->sign)
		m->width -= 1;
	if (m->c == 'p')
		m->width -= 2;
	while (m->width-- > len)
		np += write(1, &m->padd, 1);
	return (np);
}

int	fmt_str(t_mod *m, char *s)
{
	int	np;
	int	len;

	np = 0;
	len = (int)ft_strlen(s);
	np += fmt_pre(m);
	if (m->adj)
		np += write(1, s, len);
	np += fmt_padd(m, len);
	np += fmt_pos(m);
	if (!m->adj)
		np += write(1, s, len);
	return (np);
}
