/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_px.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:51:33 by aaparici          #+#    #+#             */
/*   Updated: 2021/05/22 20:08:35 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	px_pre (t_mod *m, unsigned long long int num)
{
	if (!num)
		;
	if (m->padd == '0' && (m->c == 'p'))
	{
		if (m->pre < m->width - 2)
			m->pre = m->width - 2;
		m->width = 0;
	}
}

int	c_px(t_mod *m, unsigned long long int num)
{
	int		np;
	int		i;
	char	*digits;
	char	*buf;

	px_pre(m, num);
	digits = "0123456789abcdef";
	if (m->c == 'X')
		digits = "0123456789ABCDEF";
	i = 21;
	buf = (char *)malloc(sizeof(char) * (i + 1));
	if (!buf)
		return (-1);
	buf[i] = 0;
	if (!num && m->pre < 0)
		buf[--i] = digits[0];
	while (m->pre-- > 0 || num)
	{
		buf[--i] = digits[num % 16];
		num /= 16;
	}
	np = (fmt_str(m, &buf[i]));
	free(buf);
	return (np);
}
