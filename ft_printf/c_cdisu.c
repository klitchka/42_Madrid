/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_cdisu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:51:19 by aaparici          #+#    #+#             */
/*   Updated: 2021/05/22 20:08:26 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_c(t_mod *m, char c)
{
	int	np;

	np = 0;
	if (m->adj == '-')
		write(1, &c, 1);
	while (++np < m->width)
	{
		if (m->padd == '0' && !m->adj)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	if (!m->adj)
		write(1, &c, 1);
	return (np);
}

int	c_s(t_mod *m, char *s)
{
	int	np;
	int	len;

	if (!s)
		s = "(null)";
	len = (int)ft_strlen(s);
	if (m->pre >= 0 && m->pre < len)
		len = m->pre;
	np = 0;
	if (m->adj)
		np += write(1, s, len);
	while (m->width-- > len)
		np += write(1, &m->padd, 1);
	if (!m->adj)
		np += write(1, s, len);
	return (np);
}

int	c_di(t_mod *m, long long int num)
{
	int		i;
	int		np;
	char	*buf;

	i = 21;
	buf = (char *)malloc(sizeof(char) * (i + 1));
	if (!buf)
		return (-1);
	buf[i] = 0;
	if (!num && m->pre < 0)
		buf[--i] = '0';
	if (num < 0)
	{
		m->sign = '-';
		num = -num;
	}
	while (m->pre-- > 0 || num)
	{
		buf[--i] = num % 10 + '0';
		num /= 10;
	}
	np = (fmt_str(m, &buf[i]));
	free(buf);
	return (np);
}

int	c_u(t_mod *m, unsigned long long int num)
{
	int		np;
	int		i;
	char	*buf;

	i = 21;
	buf = (char *)malloc(sizeof(char) * (i + 1));
	if (!buf)
		return (-1);
	buf[i] = 0;
	if (!num && m->pre < 0)
		buf[--i] = '0';
	while (m->pre-- > 0 || num)
	{
		buf[--i] = num % 10 + '0';
		num /= 10;
	}
	np = (fmt_str(m, &buf[i]));
	free(buf);
	return (np);
}
