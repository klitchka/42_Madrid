/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaparici <aaparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:52:08 by aaparici          #+#    #+#             */
/*   Updated: 2021/05/15 18:18:21 by aaparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_mod	*m_init(void)
{
	t_mod	*m;

	m = malloc(sizeof(t_mod));
	if (!m)
		return (NULL);
	m->sign = 0;
	m->adj = 0;
	m->padd = ' ';
	m->width = 0;
	m->pre = -1;
	m->c = 0;
	m->np = 0;
	return (m);
}

void	m_flag(const char **fmt, t_mod *m)
{
	char	c;

	c = **fmt;
	while (c == '0' || c == '-')
	{
		if (c == '-')
			m->adj = '-';
		else if (c == '0')
			m->padd = '0';
		(*fmt)++;
		c = **fmt;
	}
}

void	m_width(const char **fmt, t_mod *m, va_list args)
{
	if (**fmt == '*' && (*fmt)++)
		m->width = va_arg(args, int);
	else if (ft_isdigit(**fmt))
	{
		m->width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
	if (m->width < 0)
	{
		m->width *= -1;
		m->adj = '-';
	}
}

void	m_pre(const char **fmt, t_mod *m, va_list args)
{
	if (**fmt == '.' && (*fmt)++)
	{
		if (**fmt == '*' && (*fmt)++)
			m->pre = va_arg(args, int);
		else if (!(ft_isdigit(**fmt)))
			m->pre = 0;
		else if (ft_isdigit(**fmt))
		{
			m->pre = ft_atoi(*fmt);
			while (ft_isdigit(**fmt))
				(*fmt)++;
		}
	}
	if (m->adj == '-')
		m->padd = ' ';
}

void	m_type(const char **fmt, t_mod *m)
{
	m->c = *(*fmt)++;
	if (!(m->c == 'c' || m->c == 's') && m->pre >= 0)
		m->padd = ' ';
}
